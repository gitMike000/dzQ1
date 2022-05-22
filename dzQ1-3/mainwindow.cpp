#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->textEdit->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Edit1_Button_clicked()
{
    ui->Edit1_plainText->appendPlainText(ui->Edit2_plainText->toPlainText());
}


void MainWindow::on_Edit2_Button_clicked()
{
    ui->Edit2_plainText->setPlainText(ui->Edit1_plainText->toPlainText());
    //ui->Edit2_plainText->clear();
    //ui->Edit2_plainText->insertPlainText(ui->Edit1_plainText->toPlainText());
}


void MainWindow::on_HTML_Button_clicked()
{
   QString text="<font color='red'>Hello</font>";
   if ("" == ui->textEdit->toPlainText())
      ui->textEdit->setHtml(text);
   ui->Edit1_plainText->insertPlainText(ui->textEdit->toPlainText());
}

