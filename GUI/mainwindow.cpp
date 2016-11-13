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

//
// PAMPHLET PAGE
//

/**
 * @brief MainWindow::on_helpBtn_clicked
 * -----------------------------------------------------------------
 * This button prompts a widget which provides help to the user
 * regarding how to use the application.
 **/
void MainWindow::on_helpBtn_clicked()
{
    QMessageBox help;

    help.information(this,"Instructions","To purchase a robot click the \"Purchase a Robot\" button,\n"
                                         "although if you're an administrator, click on the \"Admin?\" "
                                         "button to be directed to the login page.");
}

/**
 * @brief MainWindow::on_adminLogBtn_clicked
 * ------------------------------------------------------------
 * This button moves the administrator to a new window
 * from which they can log into the admin portal by inputting
 * their log-in information.
 **/
void MainWindow::on_adminLoginBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminLoginPage);
    ui->adminUserLE->setFocus();
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
    ui->stackedWidget->setCurrentWidget(ui->purchasePage);
}

//
// PURCHASE LANDING PAGE
//

/**
 * @brief MainWindow::on_pBackBtn_clicked
 * ------------------------------------------------------------
 *
 **/
void MainWindow::on_pBackBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPage);
}

//
// ADMIN LOG-IN PAGE
//

/**
 * @brief MainWindow::on_backBtn_clicked
 * -------------------------------------------------------------
 * This button will go back to the pamphlet page in case a user
 * accidentally clicks on it, or the admin wants to go back.
 **/
void MainWindow::on_aBackBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPage);
    ui->adminUserLE->clear();
    ui->adminPassLE->clear();

}

/**
 * @brief MainWindow::on_adminUserLE_returnPressed
 * ------------------------------------------------------
 *
 **/
void MainWindow::on_adminUserLE_returnPressed()
{
    ui->adminPassLE->setFocus();
}

/**
 * @brief MainWindow::on_adminPassLE_returnPressed
 * ------------------------------------------------------
 *
 **/
void MainWindow::on_adminPassLE_returnPressed()
{
    ui->loginBtn->click();
}

/**
 * @brief MainWindow::on_loginBtn_clicked
 * ------------------------------------------------------
 *
 **/
void MainWindow::on_loginBtn_clicked()
{

}

//
// ADMIN LANDING PAGE
//

/**
 * @brief MainWindow::on_logOutBtn_clicked
 * ----------------------------------------------------------
 *
 **/
void MainWindow::on_logOutBtn_clicked()
{
    QMessageBox::StandardButton reply;

    // Displays a message box
    reply = QMessageBox::warning(this, tr("Logout"),
            tr("Are you sure you want to logout?"),
            QMessageBox::Ok | QMessageBox::Cancel);

    // Logout will return to login page
    if(QMessageBox::Ok == reply)
    {
        ui->stackedWidget->setCurrentWidget(ui->adminLoginPage);
        ui->adminUserLE->setFocus();
    }
}

/**
 * @brief MainWindow::on_viewListBtn_clicked
 * ----------------------------------------------------------
 *
 **/
void MainWindow::on_viewListBtn_clicked()
{

}

/**
 * @brief MainWindow::on_addDeleteCustomerBtn_clicked
 * ----------------------------------------------------------
 *
 **/
void MainWindow::on_addDeleteCustomerBtn_clicked()
{

}

/**
 * @brief MainWindow::on_updateListBtn_clicked
 * ----------------------------------------------------------
 *
 **/
void MainWindow::on_updateListBtn_clicked()
{

}
