#ifndef TABLESCHEMASSQLITE_H
#define TABLESCHEMASSQLITE_H

#include <QString>
#include <QVector>

namespace TableNamesSQLite {
    constexpr const char* PARTICIPANTS      = "participants"; // kto brał udział w pomiarach
    constexpr const char* EEG_EVENTS        = "eeg_events"; // czas rozpoczęcia w sekundach, czas trwania
    constexpr const char* EEG_FEAUTERS      = "eeg_feauters"; // moc poszczególnych pasm, moc całkowita, korekcja
    constexpr const char* STIMULI           = "stimuli"; // obwiednie, czasy beepów
    constexpr const char* EEG_CHANNELS      = "eeg_channels"; //
    constexpr const char* EEG_ELECTRODES    = "eeg_electrodes";
    constexpr const char* EEG_SESSIONS      = "eeg_sessions";
}

namespace TableSchemasSQLite {
    inline const QString CREATE_PARTICIPANTS_TABLE = QStringLiteral(R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            uuid TEXT UNIQUE NOT NULL,
            age INTEGER NOT NULL,
            sex TEXT,
            handedness TEXT,
            notes TEXT,
            created_at TEXT DEFAULT (datetime('now')),
            updated_at TEXT DEFAULT (datetime('now')),
            synced INTEGER DEFAULT 0,
            synced_at TEXT
        )
    )").arg(TableNamesSQLite::PARTICIPANTS);

    inline const QString CREATE_EEG_EVENTS_TABLE = QStringLiteral(R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            uuid TEXT UNIQUE NOT NULL,
            onset REAL,
            duration REAL,
            value TEXT,
            trial_type TEXT,
            session_id INTEGER NOT NULL,
            created_at TEXT DEFAULT (strftime('%Y-%m-%d %H:%M;%f', 'now')),
            updated_at TEXT DEFAULT (strftime('%Y-%m-%d %H:%M;%f', 'now')),
            synced INTEGER DEFAULT 0,
            synced_at TEXT,
            FOREIGN KEY(session_id) REFERENCES %2(id)
        )
    )").arg(TableNamesSQLite::EEG_EVENTS, TableNamesSQLite::EEG_SESSIONS);

    inline const QString CREATE_EEG_FEAUTERS_TABLE = QStringLiteral(R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            uuid TEXT UNIQUE NOT NULL,
            channel INTEGER,
            alpha_power REAL,
            beta_power REAL,
            theta_power REAL,
            total_power REAL,
            correlation_env REAL,
            session_id INTEGER NOT NULL,
            created_at TEXT DEFAULT (datetime('now')),
            updated_at TEXT DEFAULT (datetime('now')),
            synced INTEGER DEFAULT 0,
            synced_at TEXT,
            FOREIGN KEY(session_id) REFERENCES %2(id)
        )
    )").arg(TableNamesSQLite::EEG_FEAUTERS, TableNamesSQLite::EEG_SESSIONS);

    inline const QString CREATE_STIMULI_TABLE = QStringLiteral(R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            uuid TEXT UNIQUE NOT NULL,
            timepoint REAL,
            speaker1 REAL,
            speaker2 REAL,
            type TEXT,
            session_id INTEGER NOT NULL,
            created_at TEXT DEFAULT (datetime('now')),
            updated_at TEXT DEFAULT (datetime('now')),
            synced INTEGER DEFAULT 0,
            synced_at TEXT,
            FOREIGN KEY(session_id) REFERENCES %2(id)
        )
    )").arg(TableNamesSQLite::STIMULI, TableNamesSQLite::EEG_SESSIONS);

    inline const QString CREATE_EEG_CHANNELS_TABLE = QStringLiteral(R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT,
            type TEXT,
            units TEXT,
            session_id INTEGER NOT NULL,
            created_at TEXT DEFAULT (datetime('now')),
            updated_at TEXT DEFAULT (datetime('now')),
            FOREIGN KEY(session_id) REFERENCES %2(id)
        )
    )").arg(TableNamesSQLite::EEG_CHANNELS, TableNamesSQLite::EEG_SESSIONS);

    inline const QString CREATE_EEG_ELECTRODES_TABLE = QStringLiteral(R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT,
            coordinates REAL,
            system TEXT,
            session_id INTEGER NOT NULL,
            created_at TEXT DEFAULT (datetime('now')),
            updated_at TEXT DEFAULT (datetime('now')),
            FOREIGN KEY(session_id) REFERENCES %2(id)
        )
    )").arg(TableNamesSQLite::EEG_ELECTRODES, TableNamesSQLite::EEG_SESSIONS);

    inline const QString CREATE_EEG_SESSIONS_TABLE = QStringLiteral(R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            uuid TEXT UNIQUE NOT NULL,
            device TEXT,
            task_name TEXT,
            start_time REAL,
            end_time REAL,
            sampling_rate REAL,
            n_channels INTEGER,
            participant_id INTEGER NOT NULL,
            created_at TEXT DEFAULT (datetime('now')),
            updated_at TEXT DEFAULT (datetime('now')),
            synced INTEGER DEFAULT 0,
            synced_at TEXT,
            FOREIGN KEY(participant_id) REFERENCES %2(id)
        )
    )").arg(TableNamesSQLite::EEG_SESSIONS, TableNamesSQLite::PARTICIPANTS);

    // Zwracamy wszystkie CREATE TABLES
    inline const QStringList& createAllTables() {
        static const QStringList createAllTbl = {
            CREATE_PARTICIPANTS_TABLE,
            CREATE_EEG_SESSIONS_TABLE,
            CREATE_EEG_EVENTS_TABLE,
            CREATE_EEG_FEAUTERS_TABLE,
            CREATE_STIMULI_TABLE,
            CREATE_EEG_CHANNELS_TABLE,
            CREATE_EEG_ELECTRODES_TABLE
        };
        return createAllTbl;
    }
}

#endif // TABLESCHEMASSQLITE_H

