#include "button.h"
#include <QBrush>
#include <QGraphicsTextItem>

button::button(QString name, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //draw rect
    setRect(0, 0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);

    //draw text
    text = new QGraphicsTextItem(name, this);
    int xpos = rect().width()/2 - text->boundingRect().width()/2;
    int ypos = rect().height()/2 - text->boundingRect().height()/2;

    text -> setPos(xpos, ypos);

    setAcceptHoverEvents(true);
}

void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);
}
