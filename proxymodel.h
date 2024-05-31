#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>

class ProxyModel : public QSortFilterProxyModel {
    Q_OBJECT

public:
    explicit ProxyModel(QObject *parent = nullptr);
    void setYear(const QString &year);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QString _year;
};


#endif
