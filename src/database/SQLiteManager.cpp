#include "SQLiteManager.h"
#include "TableSchemasSQLite.h"
#include "DatabaseConfig.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <QDebug>

SQLiteManager::SQLiteManager(const QString &path)
    : dbPath_(path.isEmpty() ? DatabaseConfig::DEFAULT_SQLITE_DB_PATH : path) {}

bool SQLiteManager::initialize()
{
    db_ = QSqlDatabase::addDatabase("QSQLITE", "ear_eeg_connection");
    db_.setDatabaseName(dbPath_);

    if (!db_.open()) {
        qWarning() << "[SQLiteManager::initialize] Failed to open database: " << db_.lastError();
        return false;
    }

    qDebug() << "[SQLiteManager::initialize] Database initialize at: " << dbPath_;
    DatabaseConfig::printDbPath();

    QSqlQuery query(db_);
    for (const QString &stmts : TableSchemasSQLite::createAllTables()) {
        if (!query.exec(stmts)) {
            qWarning() << "[SQLiteManager::initialize] Failed to execute schemas: " << stmts << " Error: " << query.lastError().text();
            return false;
        }
    }

    qDebug() << "[SQLiteManager::initialize] Database initialized at: " << dbPath_;
    return true;
}

QList<QVariantMap> SQLiteManager::queryData(const QString &queryStr)
{
    QList<QVariantMap> results;

    if (!db_.isOpen()) {
        qWarning() << "[SQLiteManager::queryData] Database id not open!";
        return results;
    }

    QSqlQuery query(db_);
    if (!query.exec(queryStr)) {
        qWarning() << "[SQLiteManager::queryData] Query failed: " << query.lastError().text();
        return results;
    }

    while (query.next()) {
        QVariantMap row;
        for (int i = 0; i < query.record().count(); i++) {
            row.insert(query.record().fieldName(i), query.value(i));
        }
        results.append(row);
    }

    return results;
}

QList<QVariantMap> SQLiteManager::getUnsynced(const QString &table)
{
    QString queryStr = QString("SELECT * FROM %1 WHERE synced = 0 OR synced IS NULL").arg(table);
    return queryData(queryStr);
}

bool SQLiteManager::markAsSynced(const QString &table, const QVector<QVariantMap> &records)
{
    QSqlQuery query(db_);
    db_.transaction();
    for (const auto &record : records) {
        QString uuid = record["uuid"].toString();
        query.prepare(QString("UPDATE %1 SET synced = 1 WHERE uuid = :uuid").arg(table));
        query.bindValue(":uuid", uuid);
        if (!query.exec()) {
            qWarning() << "Failed to mark record as synced: " << query.lastError().text();
            db_.rollback();
            return false;
        }
    }
    db_.commit();
    return true;
}

bool SQLiteManager::upsertData(const QString &table,
                               const QVariantMap &data,
                               const QString &keyColumn)
{
    if (!db_.isOpen()) {
        qWarning() << "[SQLiteManager::upsertData] Database is not open!";
        return false;
    }

    QStringList columns, placeholders;
    for (auto it = data.begin(); it != data.end(); ++it) {
        columns << it.key();
        placeholders << ":" + it.key();
    }

    QString sql;
    if (keyColumn.isEmpty()) {
        // zwykły INSERT
        sql = QString("INSERT INTO %1 (%2) VALUES (%3)")
            .arg(table, columns.join(", "), placeholders.join(", "));
    } else {
        // UPSERT (INSERT OR UPDATE)
        QStringList updates;
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it.key() != keyColumn) {
                updates << QString("%1 = excluded.%1").arg(it.key());
            }
        }

        sql = QString(
          "INSERT INTO %1 (%2) VALUES (%3) "
          "ON CONFLICT(%4) DO UPDATE SET %5")
          .arg(table,
               columns.join(", "),
               placeholders.join(", "),
               keyColumn,
               updates.join(", "));
    }

    QSqlQuery query(db_);
    if (!query.prepare(sql)) {
        qWarning() << "[SQLiteManager::upsertData] Failed to prepare:" << query.lastError();
        return false;
    }

    for (auto it = data.begin(); it != data.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }

    if (!query.exec()) {
        qWarning() << "[SQLiteManager::upsertData] Failed:" << query.lastError();
        return false;
    }

    return true;
}


