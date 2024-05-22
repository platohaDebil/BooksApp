// #include "proxymodel.h"

// ProxyModel::ProxyModel(QObject* parent): QSortFilterProxyModel(parent), _genre("all"){}

// void ProxyModel::setGenre(const QString& genre){
//     if (genre != _genre){
//         _genre = genre;
//     }
//     invalidateFilter();
// }
// bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const{
//     if(_genre == "all")
//         return true;
//     QModelIndex genreIndex = sourceModel()->index(source_row, 7, source_parent);
//     QString row = sourceModel()->data(genreIndex).toString();
//     QStringList qs = row.split(", ");
//     QSet<QString> genreSet(qs.begin(), qs.end());
//     if (genreSet.find(_genre) != genreSet.end())
//         return true;
//     else
//         return false;
// }
