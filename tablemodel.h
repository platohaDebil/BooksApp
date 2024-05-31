#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QList>
#include <QObject>
#include <QWidget>
#include <QAbstractTableModel>
#include <QSet>

#include <QString>

#include "supplementary.h"



class tablemodel: public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit tablemodel(QObject *parent=nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QStringList getYear() const;

    void addBook(const Book&);
    Book getBook(const QModelIndex&);

private:
    QList<QList<QString>> _data;
    QList<QString> _header;
};

#endif // TABLEMODEL_H
