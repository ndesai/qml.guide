#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtQml>

#include "statusclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qRegisterMetaType<Status>("Status");
    qmlRegisterUncreatableType<StatusClass>("qml.guide", 1, 0, "Status", "Not creatable as it is an enum type");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
