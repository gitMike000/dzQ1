#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ac_label->hide();
    ui->ac_num->hide();
    ui->ab_SpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->ab_SpinBox->setMinimum(0.0001);
    ui->ab_SpinBox->setMaximum(1000);
    ui->bc_SpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->bc_SpinBox->setMinimum(0.0001);
    ui->bc_SpinBox->setMaximum(1000);
    ui->y_SpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->y_SpinBox->setMinimum(0.0001);
    ui->y_SpinBox->setMaximum(179);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Act_Button_clicked()
{
    double ab=ui->ab_SpinBox->value();
    double bc=ui->bc_SpinBox->value();
    double y=(ui->deg_radioButton->isChecked() ? (ui->y_SpinBox->value()*M_PI/180) : ui->y_SpinBox->value());

    double ac=qSqrt(qPow(ab,2)+qPow(bc,2)-2*ab*bc*qCos(y));
    ac=double(qRound(ac * 10000)) / 10000;
    ui->ac_num->setText(QString::number(ac));
    ui->ac_label->show();
    ui->ac_num->show();

}




void MainWindow::on_ab_SpinBox_valueChanged(double arg1)
{
    ui->ac_label->hide();
    ui->ac_num->hide();
}



void MainWindow::on_bc_SpinBox_valueChanged(double arg1)
{
    ui->ac_label->hide();
    ui->ac_num->hide();
}


void MainWindow::on_y_SpinBox_valueChanged(double arg1)
{
    ui->ac_label->hide();
    ui->ac_num->hide();
}


void MainWindow::on_rad_radioButton_toggled(bool checked)
{
    double y = ui->y_SpinBox->value();
    if (checked)
    {
        y=y*M_PI/180;
        ui->y_SpinBox->setValue(y);
    }
    else
    {
        y=y*180/M_PI;
        ui->y_SpinBox->setValue(y);
    }
}

