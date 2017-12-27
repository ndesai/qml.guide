#include "theme.h"

#include <QtQml>

static Theme *s_instance = nullptr;

Theme::Theme(QObject *parent)
    : QObject(parent)
    , m_fontFamily("Avenir")
{

}

void Theme::registerSingleton(QQmlEngine *qmlEngine)
{
    if (!s_instance) {
        s_instance = new Theme(qmlEngine);
    }
    QQmlContext *rootContext = qmlEngine->rootContext();
    rootContext->setContextProperty("Theme", s_instance);
}

QString Theme::fontFamily() const
{
    return m_fontFamily;
}

void Theme::setFontFamily(QString fontFamily)
{
    if (m_fontFamily == fontFamily)
        return;

    m_fontFamily = fontFamily;
    emit fontFamilyChanged(m_fontFamily);
}
