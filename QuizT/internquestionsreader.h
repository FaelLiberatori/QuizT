/*
 * It's an intern question reader, I will finish the implementation of the XML question reader soon.
 */

#ifndef INTERNQUESTIONSREADER_H
#include <QObject>
#include <iquestionsbase.h>
#define INTERNQUESTIONSREADER_H

class InternQuestionsReader: public IQuestionsBase
{
public:

    InternQuestionsReader()
    {
        LoadQuestions();
        RestartQuestions();
    }

    QString nextQuestion() override
    {
        QString  newQuestion = p_questions[lastQuestion];

        return newQuestion;
    }

    QString nextAnswer() override
    {
        QString  newAnswer;

        newAnswer = p_answers[lastQuestion][lastAnswer];

        return newAnswer;
    }

    bool isRight() override
    {
        bool newIsRight = p_isRight[lastQuestion][lastAnswer];

        if(lastAnswer == 3)
        {
            lastAnswer = 0;

            if(questionsCount == lastQuestion + 1)
                RestartQuestions();
            else
                lastQuestion++;
        }
        else
            lastAnswer++;

        nextAnswerChanged();
        isRightChanged();

        return newIsRight;
    }

private:
    int lastAnswer;
    int lastQuestion;
    const int questionsCount = 4;

    QString p_questions[10];
    QString p_answers[10][4];
    bool p_isRight[10][4];

    void LoadQuestions()
    {
        p_questions[0] = "Are you using the QuizT right now?";
        p_answers[0][0] = "I think not"; p_isRight[0][0] = false;
        p_answers[0][1] = "Maybe"; p_isRight[0][1] = false;
        p_answers[0][2] = "Yes, sure!"; p_isRight[0][2] = true;
        p_answers[0][3] = "No way!"; p_isRight[0][3] = false;

        p_questions[1] = "Is it free and open-source?";
        p_answers[1][0] = "Yes"; p_isRight[1][0] = true;
        p_answers[1][1] = "Nope"; p_isRight[1][1] = false;
        p_answers[1][2] = "Open what?!"; p_isRight[1][2] = true;
        p_answers[1][3] = "I don't got it"; p_isRight[1][3] = true;

        p_questions[2] = "Is it available for Linux, Mac, Windows and Android?";
        p_answers[2][0] = "Yes, I can compile it for ios and UWP by myself too"; p_isRight[2][0] = true;
        p_answers[2][1] = "No, but I can compile it for these platforms"; p_isRight[2][1] = false;
        p_answers[2][2] = "Yes, but I cannot compile it by myself"; p_isRight[2][2] = false;
        p_answers[2][3] = "No, it is only for Windows"; p_isRight[2][3] = false;

        p_questions[3] = "Complete:\nQuizT is available under the _____ free license.";
        p_answers[3][0] = "MPL"; p_isRight[3][0] = false;
        p_answers[3][1] = "LGPLv2"; p_isRight[3][1] = false;
        p_answers[3][2] = "GPLv3"; p_isRight[3][2] = true;
        p_answers[3][3] = "BSD license"; p_isRight[3][3] = false;
    }

    void RestartQuestions()
    {
        lastAnswer = 0;
        lastQuestion = 0;
    }
};

#endif // INTERNQUESTIONSREADER_H
