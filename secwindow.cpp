
#include "secwindow.h"
#include "ui_secwindow.h"
#include <QNetworkReply>
#include <QPixmap>

SecWindow::SecWindow(const Book& book, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecWindow),
    networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    ui->lineEdit_3->setText(book.reviewCount);
    ui->lineEdit_2->setText(book.rate5);
    ui->lineEdit_4->setText(book.rate4);
    ui->lineEdit_5->setText(book.rate3);
    ui->lineEdit_6->setText(book.rate2);
    ui->lineEdit_7->setText(book.rate1);
    ui->lineEdit_8->setText(book.author);
    ui->lineEdit_9->setText(book.title);

    connect(networkManager, &QNetworkAccessManager::finished, this, &SecWindow::onImageLoaded);

    QUrl url(book.link);
    QNetworkRequest request(url);
    networkManager->get(request);
}

SecWindow::~SecWindow()
{
    delete ui;
}

void SecWindow::onImageLoaded(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(data);
        ui->coverLabel->setPixmap(pixmap.scaled(ui->coverLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        ui->coverLabel->setText("ERROR");
    }
    reply->deleteLater();
}
