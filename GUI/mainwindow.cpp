#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_adminLogBtn_clicked:
 * This button moves the administrator to a new window
 * from which they can log into the admin portal by inputting
 * their log-in information.
 */
void MainWindow::on_adminLogBtn_clicked()
{

}

void MainWindow::on_helpBtn_clicked()
{

}

void MainWindow::on_purchaseBtn_clicked()
{

}


