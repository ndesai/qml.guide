#include "theme.h"

#include <QtQml>

static Theme *s_instance = nullptr;

Theme::Theme(QObject *parent)
    : QObject(parent)
    , m_fontFamily("Avenir")
{

}

void Theme::registerTypes(const char *uri)
{
    qmlRegisterSingletonType<Theme>(uri, 1, 0, "Theme", Theme::singletonProvider);
}

QObject *Theme::singletonProvider(QQmlEngine *qmlEngine, QJSEngine *)
{
    if (!s_instance) {
        s_instance = new Theme(qmlEngine);
    }
    return s_instance;
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
