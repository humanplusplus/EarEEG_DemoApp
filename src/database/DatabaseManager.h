#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include "IDataManager.h"

class DatabaseManager
{
public:
    DatabaseManager(std::unique_ptr<IDataManager> localBackend,
                    std::unique_ptr<IDataManager> cloudBackend = nullptr);

    bool initialize();
    void saveSample(const QString &table, const QVariantMap &data, const QString &keyColumn);
    void syncCloud();

protected:
    std::unique_ptr<IDataManager> local_;
    std::unique_ptr<IDataManager> cloud_;
};

#endif // DATABASEMANAGER_H
