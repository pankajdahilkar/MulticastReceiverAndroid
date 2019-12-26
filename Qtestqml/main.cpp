#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QObject>
#include <QQuickItem>
#include <QQmlProperty>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>
#include "handletextfield.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    HandleTextField handleTextField;

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    Receiver receiver_1;
    // connect our QML signal to our C++ slot
 //   QObject::connect(window, SIGNAL(submitTextField(QString)), &handleTextField, SLOT(handleSubmitTextField(QString)));

    // connect our C++ signal to our QML slot
    // NOTE: if we want to pass an parameter to our QML slot, it has to be
    // a QVariant.
    QObject::connect(&handleTextField, SIGNAL(setTextField(QVariant)),
                         window, SLOT(setTextField(QVariant)));
   QObject::connect(&receiver_1,SIGNAL(data_received(QString)),&handleTextField,SLOT(handleSubmitTextField(QString)));

    return app.exec();
}
