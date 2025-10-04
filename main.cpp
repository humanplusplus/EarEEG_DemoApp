#include <QMetaType>
#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QDir>
#include <QQuickView>

#include "src/database/SQLiteManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    SQLiteManager sqliteManager;
    if (!sqliteManager.initialize()) {
        qWarning() << "[main.cpp] Database initialization failed!";
        return -1;
    }
    qDebug() << "[main.cpp] Database initialization successfully!";

    const QUrl url(QStringLiteral("qrc:/EarEEG_DemoApp/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                //qWarning() << "QML load failed for: " << objUrl;
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
