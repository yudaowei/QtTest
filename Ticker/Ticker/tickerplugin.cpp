#include "ticker.h"
#include "tickerplugin.h"

#include <QtPlugin>

TickerPlugin::TickerPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TickerPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool TickerPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TickerPlugin::createWidget(QWidget *parent)
{
    return new Ticker(parent);
}

QString TickerPlugin::name() const
{
    return QLatin1String("Ticker");
}

QString TickerPlugin::group() const
{
    return QLatin1String("");
}

QIcon TickerPlugin::icon() const
{
    return QIcon();
}

QString TickerPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TickerPlugin::whatsThis() const
{
    return QLatin1String("Move one pixel to the left every 30 milliseconds");
}

bool TickerPlugin::isContainer() const
{
    return false;
}

QString TickerPlugin::domXml() const
{
    return QLatin1String("<widget class=\"Ticker\" name=\"ticker\">\n</widget>\n");
}

QString TickerPlugin::includeFile() const
{
    return QLatin1String("ticker.h");
}

Q_EXPORT_PLUGIN2(tickerplugin, TickerPlugin)
