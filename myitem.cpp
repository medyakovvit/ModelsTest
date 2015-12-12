#include "myitem.h"

MyItem::MyItem(int aId, int aX, int aY, QString aName, QColor aColor, QObject *parent) : QObject(parent),
    m_id(aId), m_x(aX), m_y(aY), m_name(aName), m_color(aColor)
{

}

void MyItem::setId(int id)
{
    if (m_id == id)
        return;

    m_id = id;
    emit idChanged(id);
}

void MyItem::setX(int x)
{
    if (m_x == x)
        return;

    m_x = x;
    emit xChanged(x);
}

void MyItem::setY(int y)
{
    if (m_y == y)
        return;

    m_y = y;
    emit yChanged(y);
}

void MyItem::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(name);
}

void MyItem::setColor(QColor color)
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged(color);
}

