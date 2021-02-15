#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_pressed()
{
    press("B2");
}



void MainWindow::on_pushButton_2_released()
{
    release();
}

void MainWindow::on_pushButton_pressed()
{
    press("B1");
}

void MainWindow::on_pushButton_released()
{
    release();
}


void MainWindow::press(const QString& s)
{
    auto *label = findChild<QLabel*>("label");
    QString txt = s+" Pressed";
    label->setText(txt);
}
void MainWindow::release()
{
    auto *label = findChild<QLabel*>("label");
    label->setText("");
}
