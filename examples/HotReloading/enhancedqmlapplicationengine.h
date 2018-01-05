#pragma once

#include <QQmlApplicationEngine>

class EnhancedQmlApplicationEngine : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    explicit EnhancedQmlApplicationEngine(QObject *parent = nullptr);

    Q_INVOKABLE void clearCache();
};
