#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QColor>

class MyItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int myId READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit MyItem(int aId, int aX, int aY, QString aName, QColor aColor, QObject *parent = 0);

    int id() const{return m_id;}
    int x() const{return m_x;}
    int y() const{return m_y;}
    QString name() const{return m_name;}
    QColor color() const{return m_color;}

signals:
    void idChanged(int id);
    void xChanged(int x);
    void yChanged(int y);
    void nameChanged(QString name);
    void colorChanged(QColor color);

public slots:
    void setId(int id);
    void setX(int x);
    void setY(int y);
    void setName(QString name);
    void setColor(QColor color);

protected:
    int m_id;
    int m_x;
    int m_y;
    QString m_name;
    QColor m_color;
};

#endif // MYITEM_H
