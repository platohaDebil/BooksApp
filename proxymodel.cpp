#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent): QSortFilterProxyModel(parent), _year("year") {}
void ProxyModel::setYear(const QString& year) {
    if (year != _year) {
        _year = year;
    }
    invalidateFilter();
}
bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (_year == "year")
        return true;
    QModelIndex yearIndex = sourceModel()->index(source_row, 8, source_parent);
    QString row = sourceModel()->data(yearIndex).toString();
    qDebug() << row << _year;

    // QSet<QString> yearSet;
    // for (QString x: row)
    //     yearSet.insert(x);
    if (row == _year)
        return true;
    else
        return false;
}

