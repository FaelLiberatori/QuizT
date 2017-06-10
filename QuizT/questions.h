/*
 * It's an intern question reader, I will finish the implementation of the XML question reader soon.
 */

#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QObject>

class Questions : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nextAnswer READ nextAnswer NOTIFY nextAnswerChanged)
    Q_PROPERTY(QString nextQuestion READ nextQuestion NOTIFY nextQuestionChanged)
    Q_PROPERTY(bool isRight READ isRight NOTIFY isRightChanged)

public:

    Questions()
    {
        LoadQuestions();
        RestartQuestions();
    }

    QString nextQuestion()
    {
        QString  newQuestion = p_questions[lastQuestion];

        return newQuestion;
    }

    QString nextAnswer()
    {
        QString  newAnswer;

        newAnswer = p_answers[lastQuestion][lastAnswer];

        return newAnswer;
    }

    bool isRight()
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

signals:
    void nextAnswerChanged();
    void nextQuestionChanged();
    void isRightChanged();

private:
    int lastAnswer;
    int lastQuestion;
    const int questionsCount = 10;

    QString p_questions[10];
    QString p_answers[10][4];
    bool p_isRight[10][4];

    void LoadQuestions()
    {
        p_questions[0] = "Como ocorreu o desastre de Mariana? ";
        p_answers[0][0] = "Pela destruição feita por um furacão"; p_isRight[0][0] = false;
        p_answers[0][1] = "Pelo rompimento da barragem"; p_isRight[0][1] = true;
        p_answers[0][2] = "Caiu uma árvore enorme na cidade"; p_isRight[0][2] = false;
        p_answers[0][3] = "Não ocorreu desastre, foi apenas poluição"; p_isRight[0][3] = false;

        p_questions[1] = "O que contaminou as águas subterrâneas da região onde ocorreu o desastre?";
        p_answers[1][0] = "Corante"; p_isRight[1][0] = false;
        p_answers[1][1] = "Metais pesados"; p_isRight[1][1] = true;
        p_answers[1][2] = "Agrotóxicos"; p_isRight[1][2] = false;
        p_answers[1][3] = "Lixo"; p_isRight[1][3] = false;

        p_questions[2] = "Que consequências o desastre causou para o meio ambiente?";
        p_answers[2][0] = "Matou todo o ecossistema da região"; p_isRight[2][0] = true;
        p_answers[2][1] = "Os moradores ganharam super poderes"; p_isRight[2][1] = false;
        p_answers[2][2] = "Toda a vegetão secou e explodiu"; p_isRight[2][2] = false;
        p_answers[2][3] = "Obrigou o Brasil a sair do Mercosul"; p_isRight[2][3] = false;

        p_questions[3] = "Quantas barragens de rejeitos de mineração existe no Brasil?";
        p_answers[3][0] = "663"; p_isRight[3][0] = true;
        p_answers[3][1] = "101"; p_isRight[3][1] = false;
        p_answers[3][2] = "53"; p_isRight[3][2] = false;
        p_answers[3][3] = "4"; p_isRight[3][3] = false;

        p_questions[4] = "Para onde os moradores tiveram que ir com a tragédia na época?";
        p_answers[4][0] = "Abrigos e casa de familiares"; p_isRight[4][0] = true;
        p_answers[4][1] = "Em baixo da ponte e portas de hospitais"; p_isRight[4][1] = false;
        p_answers[4][2] = "Viajar para outros países"; p_isRight[4][2] = false;
        p_answers[4][3] = "Ir para o Norte e Nordeste do país"; p_isRight[4][3] = false;

        p_questions[5] = "Hoje, a cidade finalmente se reergueu?";
        p_answers[5][0] = "Sim"; p_isRight[5][0] = false;
        p_answers[5][1] = "Tornou-se inabitável como Chernobyl"; p_isRight[5][1] = false;
        p_answers[5][2] = "Sumiu do mapa"; p_isRight[5][2] = false;
        p_answers[5][3] = "Não"; p_isRight[5][3] = true;

        p_questions[6] = "I - Samarco terá de pagar 1 milhao para retirada de objetos\nII - O presidente da Empresa Samarco teve prisão decretada e foi preso\nIII - A empresa suspendeu por dois meses contratos de 800 funcionários\nAs seguintes afirmações estão corretas:";
        p_answers[6][0] = "Todas estão corretas"; p_isRight[6][0] = false;
        p_answers[6][1] = "Nenhuma está correta"; p_isRight[6][1] = false;
        p_answers[6][2] = "Apenas I e III estão corretas"; p_isRight[6][2] = true;
        p_answers[6][3] = "Apenas III e II estão corretas"; p_isRight[6][3] = false;

        p_questions[7] = "Há quanto tempo ocorreu a tragédia?";
        p_answers[7][0] = "1 ano e 6 meses"; p_isRight[7][0] = false;
        p_answers[7][1] = "1 ano e 8 meses"; p_isRight[7][1] = false;
        p_answers[7][2] = "2 anos e 7 meses"; p_isRight[7][2] = false;
        p_answers[7][3] = "1 ano e 7 meses"; p_isRight[7][3] = true;

        p_questions[8] = "Que tipo de rocha era extraída na mineradora?";
        p_answers[8][0] = "Diamante"; p_isRight[8][0] = false;
        p_answers[8][1] = "Ouro"; p_isRight[8][1] = false;
        p_answers[8][2] = "Quartzo"; p_isRight[8][2] = true;
        p_answers[8][3] = "Lure"; p_isRight[8][3] = false;

        p_questions[9] = "Gostou de nossa apresentação?";
        p_answers[9][3] = "Sim"; p_isRight[9][0] = true;
        p_answers[9][2] = "Não"; p_isRight[9][1] = true;
        p_answers[9][0] = "Podia ser melhor"; p_isRight[9][2] = true;
        p_answers[9][1] = "Teria sido melhor ver o filme do pelé!"; p_isRight[9][3] = true;
    }

    void RestartQuestions()
    {
        lastAnswer = 0;
        lastQuestion = 0;
    }
};

#endif // QUESTIONS_H
