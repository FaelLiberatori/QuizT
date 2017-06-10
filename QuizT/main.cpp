#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <questions.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("questionsDB", new Questions);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
