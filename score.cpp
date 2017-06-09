#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{
    //1. Initialize score to 0.
    score = 0;

    //2. Draw text.
    setPlainText(QString("Score: ") + QString::number(score)); //will look like Score: 0

    //3. Make it prettier: set color, set font type & size
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16)); //font and size
}

void Score::increase()
{
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
