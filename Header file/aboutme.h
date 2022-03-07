#ifndef ABOUTME_H
#define ABOUTME_H

#include <QDialog>
#include <QMainWindow>
#include <QDesktopServices>

namespace Ui {
class AboutMe;
}

class AboutMe : public QDialog
{
    Q_OBJECT

public:
    explicit AboutMe(QWidget *parent = nullptr);
    ~AboutMe();

private slots:

    void on_Resume_clicked();

private:
    Ui::AboutMe *ui;
};

#endif // ABOUTME_H
