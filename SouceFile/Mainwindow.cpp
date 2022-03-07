#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include<QFont>
#include<QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFileName = "";
    ui->textEdit ->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString openFile = QFileDialog::getOpenFileName(this, "Open A File");
    currentFileName = openFile;

    QFile file(openFile);
    QString line;

    if(file.open(QIODevice :: ReadOnly | QIODevice :: Text))
    {
        QTextStream textStream(&file);

        while (!textStream.atEnd())
        {
            line.append(textStream.readLine()+"\n");
        }
    }

    ui -> textEdit -> setPlainText(line);

}

void MainWindow::on_actionSave_triggered()
{
    if(currentFileName == ""){
        on_actionSaveas_triggered();
    }
    else{
        QFile saveFile(currentFileName);
        if(saveFile.open(QFile :: WriteOnly | QFile :: Text)){
            QTextStream  out(&saveFile);
            out << ui -> textEdit -> toPlainText();
            saveFile.flush();
            saveFile.close();
        }
    }
    ui->statusbar->showMessage("Saved to "+currentFileName);

}

void MainWindow::on_actionSaveas_triggered()
{
    QString saveFileName = QFileDialog::getSaveFileName(this, "Save As");
    if(!saveFileName.isEmpty())
    {
        currentFileName = saveFileName;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionExit_triggered()
{
   QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionBold_triggered()
{
    QFont font = ui -> textEdit -> currentFont();
    font.bold() == true ? font.setBold(false) : font.setBold(true);
    ui -> textEdit -> setCurrentFont(font);
}











void MainWindow::on_actionSuperscript_triggered()
{
    Subscript -> setChecked(false);
    QTextCharFormat format;

    if(Superscript -> isChecked())
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    else
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);

    ui -> textEdit -> mergeCurrentCharFormat(format);
}



void MainWindow::on_actionSubscript_triggered()
{
    Superscript -> setChecked(false);
        QTextCharFormat format;

        if(Subscript -> isChecked())
            format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
        else
            format.setVerticalAlignment(QTextCharFormat::AlignNormal);

        ui -> textEdit -> mergeCurrentCharFormat(format);
}



void MainWindow::on_actionMe_triggered()
{
    QString url = "https://drive.google.com/file/d/1Me5YdbMRcP4jZqX5a03vcD0fP2QXcYCs/view?usp=drivesdk";
        QDesktopServices::openUrl(url);
}
void MainWindow::on_pushButton_clicked()
{
    on_actionAbout_Me_triggered();
}
