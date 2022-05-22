#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->answer->hide();
    ui->x1_label->hide();
    ui->x1_num->hide();
    ui->x2_label->hide();
    ui->x2_num->hide();
    ui->a_SpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->a_SpinBox->setMinimum(-1000);
    ui->a_SpinBox->setMaximum(1000);
    ui->b_SpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->b_SpinBox->setMinimum(-1000);
    ui->b_SpinBox->setMaximum(1000);
    ui->c_SpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->c_SpinBox->setMinimum(-1000);
    ui->c_SpinBox->setMaximum(1000);      
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Act_Button_clicked()
{
    double a=ui->a_SpinBox->value();
    double b=ui->b_SpinBox->value();
    double c=ui->c_SpinBox->value();
    if (0 == a)
    {
        double x1=-c/b;
        ui->x1_num->setText(QString::number(x1));
        ui->x1_label->show();
        ui->x1_num->show();
    }
    else
    {
     double d=qPow(b,2)-4*a*c;
     if (d < 0)
     {
         ui->answer->show();
         return;
     }
     double x1=(-b+qSqrt(d))/(2*a);
     if (0 == d)
     {
      ui->x1_num->setText(QString::number(x1));
      ui->x1_label->show();
      ui->x1_num->show();
     }
     else
     {
      double x2=(-b-qSqrt(d))/(2*a);
      ui->x1_num->setNum(x1);
      ui->x2_num->setNum(x2);
      ui->x1_label->show();
      ui->x1_num->show();
      ui->x2_label->show();
      ui->x2_num->show();
     }
    }

}




void MainWindow::on_a_SpinBox_valueChanged(double arg1)
{
    ui->answer->hide();
    ui->x1_label->hide();
    ui->x1_num->hide();
    ui->x2_label->hide();
    ui->x2_num->hide();
}



void MainWindow::on_b_SpinBox_valueChanged(double arg1)
{
    ui->answer->hide();
    ui->x1_label->hide();
    ui->x1_num->hide();
    ui->x2_label->hide();
    ui->x2_num->hide();
}


void MainWindow::on_c_SpinBox_valueChanged(double arg1)
{
    ui->answer->hide();
    ui->x1_label->hide();
    ui->x1_num->hide();
    ui->x2_label->hide();
    ui->x2_num->hide();
}

