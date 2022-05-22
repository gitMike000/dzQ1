#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
                 void on_Act_Button_clicked();

                 void on_ab_SpinBox_valueChanged(double arg1);

                 void on_bc_SpinBox_valueChanged(double arg1);

                 void on_y_SpinBox_valueChanged(double arg1);

                 void on_rad_radioButton_toggled(bool checked);

             private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
