#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include "colormaker.h"
#include "imageprocessor.h"
#include "EasyTableModel.h"
#include <QQuickStyle>
#include <QQmlContext>
#include "dynamiclistmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<ColorMaker>("an.qt.ColorMaker", 1, 0, "ColorMaker");
    qmlRegisterType<ImageProcessor>("an.qt.ImageProcessor", 1, 0, "ImageProcessor");
    qmlRegisterType<EasyTableModel>("EasyModel",1,0,"EasyTableModel");

//    QQuickStyle::setStyle("Universal");
    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    DynamicListModel temp;
    ctx->setContextProperty("dynamicModel", &temp);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
