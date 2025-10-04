#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(std::unique_ptr<IDataManager> localBackend,
                                 std::unique_ptr<IDataManager> cloudBackend)
    : local_(std::move(localBackend)),
      cloud_(std::move(cloudBackend))
{}

bool DatabaseManager::initialize()
{
    bool ok = true;

    if (local_) {
        ok &= local_->initialize();
    } else {
        qWarning() << "[DatabaseManager] No local backend provided!";
    }

    if (cloud_) {
        ok &= cloud_->initialize();
    }

    return ok;
}

void DatabaseManager::saveSample(const QString &table, const QVariantMap &data, const QString &keyColumn)
{
    // if (local_) {
    //     if (!local_->upsertData(data)) {
    //         qWarning() << "[DatabaseManager] Failed to insert sample locally!";
    //     }
    // }

    // if (cloud_) {
    //     if (!cloud_->upsertData(data)) {
    //         qWarning() << "[DatabaseManager] Failed to insert sample to cloud!";
    //     }
    // }
}

void DatabaseManager::syncCloud()
{
    qDebug() << "[DatabaseManager] No cloud backend, skipping sync.";
    // if (cloud_) {
    //     cloud_->sync();
    // } else {
    //     qDebug() << "[DatabaseManager] No cloud backend, skipping sync.";
    // }
}
