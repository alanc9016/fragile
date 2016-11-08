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
 * @brief MainWindow::on_adminLogBtn_clicked
 * ------------------------------------------------------------
 * This button moves the administrator to a new window
 * from which they can log into the admin portal by inputting
 * their log-in information.
 **/
void MainWindow::on_adminLogBtn_clicked()
{

}

<<<<<<< HEAD
/**
 * @brief MainWindow::on_helpBtn_clicked
 * -----------------------------------------------------------------
 * This button prompts a widget which provides help to the user
 * regarding how to use the application.
 **/
=======
/*!
 * \brief MainWindow::on_helpBtn_clicked:
 * This button gives an explanation on how
 * to operate the program
 */
>>>>>>> 98bf94e8f44bbd5369709a6547c5939f02f2ee58
void MainWindow::on_helpBtn_clicked()
{
    QMessageBox help;

    help.information(this,"Instructions","To purchase a robot click the Purchase a Robot button!\nIf you're"
                                         " an administrator click on the Admin? button!");
}

/**
 * @brief MainWindow::on_purchaseBtn_clicked
 * -------------------------------------------------------------------
 * This button sends the user to another window which shows them
 * four different options to purchase a robot. Each robot's listing
 * includes its name, price, and quantity.
 **/
void MainWindow::on_purchaseBtn_clicked()
{

}


