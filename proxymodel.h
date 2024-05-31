#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit ProxyModel(QObject *parent = nullptr);
    void setYear(const QString &year);
    void setAuthor(const QString &author);
    void setTitle (const QString &title);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QString _year;
    QString _author;
    QString _title;
};
#endif
