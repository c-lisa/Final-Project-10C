#include "score.h"
#include<QFont>
#include "game.h"

extern Game * game;

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initialize score
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("arial", 16));
}

void Score::increase()
{
    ++score;
    if (score%20 == 0)
    {
        game -> health -> increase();
    }

    displayScore();
}

void Score::displayScore()
{
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}


