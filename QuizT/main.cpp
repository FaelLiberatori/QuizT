#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <imagereader.h>
#include <internquestionsreader.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ImageReader* backgroundImages = new ImageReader(":/images/Backgrounds/");

    InternQuestionsReader* questionDB = new InternQuestionsReader; // Choose what one you want to use by default
    //xmlQuestionReader* questionDB = new xmlQuestionReader; // by commenting or uncommenting these 2 lines

    engine.rootContext()->setContextProperty("questionsDB", questionDB);
    engine.rootContext()->setContextProperty("backgroundImages", backgroundImages);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
