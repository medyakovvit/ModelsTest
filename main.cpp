#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "mymodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);    

    QQmlApplicationEngine engine;
    MyModel model;
    engine.rootContext()->setContextProperty("myModel", &model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

