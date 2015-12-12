#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "myitem.h"

class MyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum {
        ID = Qt::UserRole + 1,
        X,
        Y,
        NAME,
        COLOR
    };

    MyModel(QObject *parent=0);
    ~MyModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

protected:
    QHash<int, QByteArray> roleNames() const;

protected:
    void createItems();

protected:
    QList<MyItem*> m_items;
};

#endif // MYMODEL_H
