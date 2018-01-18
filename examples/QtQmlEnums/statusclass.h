#pragma once

#include <QObject>

class StatusClass
{
    Q_GADGET
public:
    enum Value {
        Null,
        Ready,
        Loading,
        Error
    };
    Q_ENUM(Value)

private:
    explicit StatusClass();
};

typedef StatusClass::Value Status;
