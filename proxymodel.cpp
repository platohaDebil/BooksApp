#include "proxymodel.h"

ProxyModel::ProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
    , _year("year"),_author(""),_title("")
{}
void ProxyModel::setYear(const QString &year)
{
    if (year != _year) {
        _year = year;
    }
    invalidateFilter();
}

void ProxyModel::setTitle(const QString &title)
{
    if (title != _title) {
        _title = title;
    }
    invalidateFilter();
}

void ProxyModel::setAuthor(const QString &author)
{
    if (author != _author) {
        _author = author;
    }
    invalidateFilter();
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex authorIndex = sourceModel()->index(source_row, 7, source_parent);
    QString author = sourceModel()->data(authorIndex).toString();
    QModelIndex titleIndex = sourceModel()->index(source_row, 10, source_parent);
    QString title = sourceModel()->data(titleIndex).toString();

    if (!_author.isEmpty()) {
       return ((author.contains(_author, Qt::CaseInsensitive)) || (title.contains(_author, Qt::CaseInsensitive)));
    }

    if (_year == "year")
        return true;
    QModelIndex yearIndex = sourceModel()->index(source_row, 8, source_parent);
    QString row = sourceModel()->data(yearIndex).toString();


    if (row == _year)
        return true;
    else
        return false;
}

