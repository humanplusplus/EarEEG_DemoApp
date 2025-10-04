#ifndef DATABASECONFIG_H
#define DATABASECONFIG_H

#include <QDir>
#include <QDebug>
#include <QString>
#include <QStandardPaths>

namespace DatabaseConfig {
    inline const QString DEFAULT_SQLITE_DB_PATH = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator() + "ear_eeg.db";
    inline const QString DEFAULT_SQLITE_DB_PATH_TEST = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator() + "ear_eeg_test.db";

    // W Superbase projekt: EarEEG_DemoApp
    inline const QString SUPABASE_URL = "https://puxbexbujbuxcdykzpnn.supabase.co";
    inline const QString SUPABASE_API_KEY = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InB1eGJleGJ1amJ1eGNkeWt6cG5uIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NTg2NDUxMDEsImV4cCI6MjA3NDIyMTEwMX0.z2xH79tc_hHnlCDdDK4bZjG-oOTUgo2hrQhiRPvFjCY";

    // W Superbase projekt: EarEEG_DemoApp_Test
    inline const QString SUPABASE_URL_TEST = "https://bnbxaghtwjuhmxxqpsyh.supabase.co";
    inline const QString SUPABASE_API_KEY_TEST = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImJuYnhhZ2h0d2p1aG14eHFwc3loIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NTg3Mjc2MTQsImV4cCI6MjA3NDMwMzYxNH0.YeeoZPJStgTajm1NCr44vELYvHEdnH3ZD86ID8kEviI";

    inline void printDbPath() {
        qDebug() << "[DatabaseConfig] Using SQLite database at: " << DEFAULT_SQLITE_DB_PATH;
    }
}

#endif // DATABASECONFIG_H
