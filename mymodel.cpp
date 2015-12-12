#include "mymodel.h"

MyModel::MyModel(QObject *parent) : QAbstractListModel(parent)
{
    createItems();
}

MyModel::~MyModel()
{
    qDeleteAll(m_items);
    m_items.clear();
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_items.size();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    MyItem *item = m_items.at(index.row());

    if (!item)
        return QVariant();

    switch (role) {
    case ID:
        return item->id();
    case X:
        return item->x();
    case Y:
        return item->y();
    case NAME:
        return item->name();
    case COLOR:
        return item->color();

    default:
        return QVariant();
    }
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;

    MyItem *item = m_items.at(index.row());
    bool changed = false;
    QVector<int> changedRoles;

    switch (role) {
    case ID:
        item->setId(value.toInt());
        changedRoles.append(ID);
        break;
    case X:
        item->setX(value.toInt());
        changedRoles.append(X);
        break;
    case Y:
        item->setY(value.toInt());
        changedRoles.append(Y);
        break;
    case NAME:
        item->setName(value.toString());
        changedRoles.append(NAME);
        break;
    case COLOR:
    {
        QColor color = value.value<QColor>();
        item->setColor(color);
        changedRoles.append(COLOR);
        break;
    }

    default:
        break;
    }
    if (changedRoles.isEmpty())
        return false;

    else
    {
        emit dataChanged(index, index, changedRoles);
        return true;
    }
}

QHash<int, QByteArray> MyModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(ID, "aId");
    roles.insert(X, "aX");
    roles.insert(Y, "aY");
    roles.insert(NAME, "aName");
    roles.insert(COLOR, "aColor");
    return roles;
}

void MyModel::createItems()
{
    m_items.append(new MyItem(0, 0, 0, "first", QColor(255, 0, 0), this));
    m_items.append(new MyItem(1, 40, 27, "second", QColor(0, 255, 0), this));
    m_items.append(new MyItem(2, 18, 23, "third", QColor(0, 0, 255), this));
    m_items.append(new MyItem(3, 15, 9, "fourth", QColor(255, 255, 0), this));
}

