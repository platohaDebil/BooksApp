#include "tablemodel.h"
#include <QFile>
#include <QMessageBox>

tablemodel::tablemodel(QObject *parent): QAbstractTableModel(parent)
{
    QFile file("C:\\Users\\Alex\\QT\\BooksApp\\BooksApp\\data\\books.csv");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ss(&file);
    QString s = ss.readLine();
    _header = s.split(",");
    //_header[0].remove("\"");
    //(_header[_header.size()-1]).remove("\"");
    QList <QString> row;

    while (!ss.atEnd())
    {
        s = ss.readLine();
        row = s.split(",");
        row[8].remove(".0");
        row[7].remove('"');
        //row[0].remove("\"");
        //(row.end() - 1)->remove("\"");
        _data.append(row);
    }


    file.close();
}

int tablemodel::rowCount(const QModelIndex &parent) const
{
    return _data.size();
}

int tablemodel::columnCount(const QModelIndex &parent) const
{
    return _header.size();
}

QVariant tablemodel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return QVariant(_data[index.row()][index.column()]);
    return QVariant();
}
QVariant tablemodel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role == Qt::DisplayRole){
        if (orientation == Qt::Horizontal){
            return _header[section];
        }
        return section;
    }
    return QVariant();
}
QSet<QString> tablemodel::getYear() const{
    QSet<QString> set;
    int position = _header.indexOf("original_publication_year");
    for(const QList<QString>& row :_data){
        set.insert( row.at(position));
    }
    return set;
}
