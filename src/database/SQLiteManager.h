#ifndef SQLITEMANAGER_H
#define SQLITEMANAGER_H

#include <QSqlDatabase>

#include "IDataManager.h"

class SQLiteManager : public IDataManager
{
public:
    explicit SQLiteManager(const QString &path = QString());

    bool initialize() override;
    bool upsertData(const QString &table, const QVariantMap &data, const QString &keyColumn) override;
    QList<QVariantMap> queryData(const QString &queryStr) override;

    QList<QVariantMap> getUnsynced(const QString &table);
    bool markAsSynced(const QString &table, const QVector<QVariantMap> &records);

protected:
    QSqlDatabase db_;
    QString dbPath_;
};

#endif // SQLITEMANAGER_H
