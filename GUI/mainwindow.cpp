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

/*!
 * \brief MainWindow::on_helpBtn_clicked:
 * This button gives an explanation on how
 * to operate the program
 */
void MainWindow::on_helpBtn_clicked()
{
    QMessageBox help;

    help.information(this,"Instructions","To purchase a robot click the Purchase a Robot button!\nIf you're"
                                         " an administrator click on the Admin? button!");
}

void MainWindow::on_purchaseBtn_clicked()
{

}


