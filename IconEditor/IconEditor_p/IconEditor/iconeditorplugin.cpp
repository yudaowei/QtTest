#include "iconeditor.h"
#include "iconeditorplugin.h"

#include <QtPlugin>

IconeditorPlugin::IconeditorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void IconeditorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool IconeditorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *IconeditorPlugin::createWidget(QWidget *parent)
{
    return new IconEditor(parent);
}

QString IconeditorPlugin::name() const
{
    return QLatin1String("Iconeditor");
}

QString IconeditorPlugin::group() const
{
    return QLatin1String("Image Maipulation Widgets");
}

QIcon IconeditorPlugin::icon() const
{
    return QIcon();
}

QString IconeditorPlugin::toolTip() const
{
    return QLatin1String("An icon editor widget");
}

QString IconeditorPlugin::whatsThis() const
{
    return QLatin1String("This widget is presented in Chapter 5 of <i>C++ GUI. Programming wit好Qt4</i> as an example of a custom Qt widget.");
}

bool IconeditorPlugin::isContainer() const
{
    return false;
}

QString IconeditorPlugin::domXml() const
{
    return QLatin1String("<widget class=\"Iconeditor\" name=\"iconeditor\">\n</widget>\n");
}

QString IconeditorPlugin::includeFile() const
{
    return QLatin1String("iconeditor.h");
}

Q_EXPORT_PLUGIN2(Iconeditorplugin, IconeditorPlugin)
