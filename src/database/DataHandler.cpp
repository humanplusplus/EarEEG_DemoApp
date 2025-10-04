#include <QDebug>
#include <qdatetime.h>

#include "DataHandler.h"
#include "../database/SQLiteManager.h"
#include "TableSchemasSQLite.h"

DataHandler::DataHandler(SQLiteManager *db, QObject *parent)
    : QObject(parent), db_(db) {}

void DataHandler::handleBatch(const QVector<QVariantMap> &batch)
{
    int ok = 0;
    int fail = 0;

    for (const auto &row : batch) {
        db_->upsertData(TableNamesSQLite::EEG_FEAUTERS, row, "uuid");
    }
    qDebug() << "[DataHandler] Inserted batch of: " << batch.size() << " samples";

}
