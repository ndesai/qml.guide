#pragma once

#include <QObject>
#include <QQmlEngine>

class Theme : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fontFamily READ fontFamily WRITE setFontFamily NOTIFY fontFamilyChanged)

public:
    explicit Theme(QObject *parent = nullptr);
    static void registerTypes(const char *uri);
    static QObject *singletonProvider(QQmlEngine *, QJSEngine *);

    QString fontFamily() const;

public slots:
    void setFontFamily(QString fontFamily);

signals:
    void fontFamilyChanged(QString fontFamily);

private:
    QString m_fontFamily;
};
