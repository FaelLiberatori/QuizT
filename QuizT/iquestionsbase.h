#ifndef IQUESTIONSBASE_H
#include <QObject>
#define IQUESTIONSBASE_H

class IQuestionsBase: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nextAnswer READ nextAnswer NOTIFY nextAnswerChanged)
    Q_PROPERTY(QString nextQuestion READ nextQuestion NOTIFY nextQuestionChanged)
    Q_PROPERTY(bool isRight READ isRight NOTIFY isRightChanged)

signals:
    void nextAnswerChanged();
    void nextQuestionChanged();
    void isRightChanged();

public:
    virtual ~IQuestionsBase() {}
    virtual bool isRight() = 0;
    virtual QString nextAnswer() = 0;
    virtual QString nextQuestion() = 0;

};

#endif //IQUESTIONSBASE_H
