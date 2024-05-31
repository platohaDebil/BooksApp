#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <QObject>
#include <QSet>
#include <QWidget>
#include <algorithm>
#include <QString>

#include "supplementary.h"

class tablemodel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit tablemodel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QSet<QString> getYear() const;

    void addBook(const Book &);

private:
    QList<QList<QString>> _data;
    QList<QString> _header;
};

#endif // TABLEMODEL_H
