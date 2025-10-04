#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QVector>
#include <QVariantMap>

#include "../database/SQLiteManager.h"

class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(SQLiteManager *db, QObject *parent = nullptr);

public slots:
    void handleBatch(const QVector<QVariantMap> &batch);

protected:
    SQLiteManager *db_;
};

#endif // DATAHANDLER_H
