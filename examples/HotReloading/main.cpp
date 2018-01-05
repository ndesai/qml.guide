#include <QGuiApplication>
#include <QQmlContext>

#include "enhancedqmlapplicationengine.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    EnhancedQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("$QmlEngine", &engine);

    engine.load(QUrl(qgetenv("MAIN_QML")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
