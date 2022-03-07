#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCore>
#include <QColorDialog>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QtWidgets>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


    public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSuperscript_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSaveas_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionBold_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionSubscript_triggered();

    void on_actionExit_triggered();

    void on_actionMe_triggered();




private:
    Ui::MainWindow *ui;
    QString currentFileName= "";

    QPointer<QAction> Subscript = nullptr;
    QPointer<QAction> Superscript = nullptr;
};
#endif // MAINWINDOW_H
