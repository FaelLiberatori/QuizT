#ifndef XMLQUESTIONSREADER_H
#define XMLQUESTIONSREADER_H

#include <QObject>
#include <QXmlStreamReader>
#include <QFile>

class XmlQuestionsReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool rightAnswer READ rightAnswer NOTIFY rightAnswerChanged)
    Q_PROPERTY(QString nextAnswer READ nextAnswer NOTIFY nextAnswerChanged)
    Q_PROPERTY(QString nextQuestion READ nextQuestion NOTIFY nextQuestionChanged)
public:
    QFile* xmlFile = new QFile("/home/rafael/Documentos/text.xml");

    XmlQuestionsReader()
    {
        if (xmlFile->exists())
        {
            if(xmlFile->open(QIODevice::ReadOnly | QIODevice::Text))
            {
                xmlReader.setDevice(xmlFile);
                p_rightAnswer = false;
                rightAnswerChanged();
                SetNextQuestion();
            }
            else if (xmlReader.hasError())
            {
                p_nextQuestion = (QString) xmlReader.errorString();
            }
            else
            {
                p_nextQuestion = "Error when opening the XML file.";
                p_nextQuestion += "\n" + xmlReader.error();
            }
        }
        else
            p_nextQuestion = "Error: XML file does not exist.";
    }

    bool rightAnswer()
    {
        return p_rightAnswer;
    }

    QString nextQuestion()
    {
        return p_nextQuestion;
    }

    QString nextAnswer()
    {
        lastAnswer++;
        if(lastAnswer - 1 == 3)
            SetNextQuestion();

        if(lastAnswer == trueAnswer)
        {
            p_rightAnswer = true;
            rightAnswerChanged();
        }

        return answerArray[lastAnswer - 1];
    }


signals:
    void nextQuestionChanged();
    void rightAnswerChanged();
    void nextAnswerChanged();
private:
    QString p_nextQuestion;
    bool p_rightAnswer;
    QString answerArray[4];
    int lastAnswer;
    int trueAnswer = 0;
    QXmlStreamReader xmlReader;

    void SetNextQuestion()
    {
        if(!xmlReader.isEndDocument())
        {
            while(xmlReader.name().toString() != "wording")
            {
                xmlReader.readNext();

                if(!xmlReader.isEndDocument())
                {
                    xmlReader.clear();
                    xmlReader.setDevice(xmlFile);
                }
            }

            p_nextQuestion = xmlReader.readElementText();
            xmlReader.readNext();
            nextQuestionChanged();
        }
        else
        {
            xmlReader.clear();
            xmlReader.setDevice(xmlFile);
            SetNextQuestion();
        }

        SetNextAnswers();
    }

    void SetNextAnswers()
    {
        lastAnswer = 0;

        if(!xmlReader.isEndDocument())
        {
            QString name = xmlReader.name().toString();
            if(name == "right" || name == "wrong")
            {
               for(int i = 0; i < 4; i++)
               {
                   answerArray[i] = xmlReader.readElementText();

                   if(name == "right")
                       trueAnswer = i + 1;

                   xmlReader.readNext();
                   name = xmlReader.name().toString();
               }

               nextAnswerChanged();
            }else if (xmlReader.isEndElement())
            {
                for(int i = 0; i < 4; i++)
                    answerArray[i] = "Error: You need calls questions before answers!";
            }
        }
        else
        {
            xmlReader.clear();
            xmlReader.setDevice(xmlFile);
            SetNextQuestion();
        }
    }
};

#endif // XMLQUESTIONSREADER_H
