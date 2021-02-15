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
    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;

    void press(const QString& s);
    void release();
};
#endif // MAINWINDOW_H
