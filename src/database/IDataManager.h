#ifndef IDATAMANAGER_H
#define IDATAMANAGER_H

#include <QString>
#include <QVariantMap>

class IDataManager
{
public:
    virtual ~IDataManager() = default;

    virtual bool initialize() = 0;
    virtual bool upsertData(const QString &table, const QVariantMap &data, const QString &keyColumn) = 0;
    virtual QList<QVariantMap> queryData(const QString &queryStr) = 0;
};

#endif // IDATAMANAGER_H
