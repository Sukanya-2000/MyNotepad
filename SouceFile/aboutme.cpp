#include "includes/aboutme.h"
#include "ui_aboutme.h"

AboutMe::AboutMe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMe)
{
    ui->setupUi(this);
    QPalette p = ui -> textBrowser -> palette();
    p.setColor(QPalette::Base, "#1e1e1e");
    p.setColor(QPalette::Text, Qt::white);
    ui -> textBrowser -> setPalette(p);

}

AboutMe::~AboutMe()
{
    delete ui;
}


void AboutMe::on_viewResume_clicked()
{
    QString url = "https://drive.google.com/file/d/1Me5YdbMRcP4jZqX5a03vcD0fP2QXcYCs/view?usp=drivesdk";
    QDesktopServices::openUrl(url);
}

