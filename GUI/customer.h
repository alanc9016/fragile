#ifndef CUSTOMER
#define CUSTOMER


#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QTextStream>
#include <QVector>
#include <iostream>
#include <QMessageBox>
#include <QRegExp>

/**
 * @brief MAXNAME
 * maximum size of name field
 */
const int MAXNAME = 50;
/**
 * @brief MAXSTREET
 * maximum size of street field
 */
const int MAXSTREET = 75;
/**
 * @brief MAXCITY
 * maximum size of city field
 */
const int MAXCITY = 50;
/**
 * @brief MAXSTATE
 * maximum size of state field
 */
const int MAXSTATE = 2;
/**
 * @brief MAXZIP
 * maximum size of zip field
 */
const int MAXZIP = 5;
/**
 * @brief MAXINTEREST
 * maximum size of interest field
 */
const int MAXINTEREST = 50;
/**
 * @brief MAXSTATUS
 * maximum size of status field
 */
const int MAXSTATUS = 50;
/**
 * @brief MAXTEST
 * maximum size of testimonial field
 */
const int MAXTEST = 300;
/**
 * @brief MAXREQ
 * maximum size of requested field
 */
const int MAXREQ = 50;

/**
 * @brief The customer class
 */
class customer
{
private:
    QString name;///> Name of Customer
    QString street;///> Street Address of Customer
    QString city;///> City of Customer
    QString state;///> State (postal) of Customer
    QString	zip;///> Zip code of Customer
    QString status;///> Status of Customer (key or nice to have)
    QString interest;///> Interest level of Customer (very, somewhat, or not interested, may be never call again)
    QString testimonial;///> Testimonial of Customer (default null)
    QString requested;///> Status of requested pamphlet by customer
    bool isActive;///> 1 active, 0 inactive or deleted
    int robot1;///> number of robot1's ordered
    int robot2;///> number of robot2's ordered
    int robot3;///> number of robot3's ordered
public:
    /**
     * @brief customer
     * Default constructor will make a student with entirely default values.
     * Such a customer should never be stored in the database
     */
    customer();
    /**
     * @brief customer
     * Constructor with parameters will construct a customer object with all values
     * given. May not be used as much
     */
    customer(QString, QString, QString, QString, QString, QString, QString, QString, QString, int r1, int r2, int r3);
    /**
     * @brief customer
     * Customer constructor that will take name, address, and status. Will most likely be used
     */
    customer(QString, QString, QString, QString, QString, QString);
    /**
     * @brief setName
     */
    void setName(QString);
    /**
     * @brief setStreet
     */
    void setStreet(QString);
    /**
     * @brief setCity
     */
    void setCity(QString);
    /**
     * @brief setState
     */
    void setState(QString);
    /**
     * @brief setZip
     */
    void setZip(QString);
    /**
     * @brief setStatus
     */
    void setStatus(QString);
    /**
     * @brief setInterest
     */
    void setInterest(QString);
    /**
     * @brief setTestimonial
     */
    void setTestimonial(QString);
    /**
     * @brief setRequested
     */
    void setRequested(QString);
    /**
     * @brief setActive
     */
    void setActive(bool);
    /**
     * @brief setRobot1
     */
    void setRobot1(int);
    /**
     * @brief setRobot2
     */
    void setRobot2(int);
    /**
     * @brief setRobot3
     */
    void setRobot3(int);
    /**
     * @brief getName
     * @return
     * name of customer
     */
    QString getName() const;
    /**
     * @brief getStreet
     * @return
     * street address of customer
     */
    QString getStreet() const;
    /**
     * @brief getCity
     * @return
     * city of customer
     */
    QString getCity() const;
    /**
     * @brief getState
     * @return
     * state of customer
     */
    QString getState() const;
    /**
     * @brief getZip
     * @return
     * zipcode of customer
     */
    QString getZip() const;
    /**
     * @brief getStatus
     * @return
     * status of customer, either key or nice to have
     */
    QString getStatus() const;
    /**
     * @brief getInterest
     * @return
     * interest level of customer
     */
    QString getInterest() const;
    /**
     * @brief getTestimonial
     * @return
     * testimonial of customer
     */
    QString getTestimonial() const;
    /**
     * @brief getRequested
     * @return
     * status of customer's request for pamphlet
     */
    QString getRequested() const;
    /**
     * @brief getActive
     * @return
     * bool of whether customer is active or not
     */
    bool getActive() const;

    /**
     * @brief printCustomer
     * @return
     * print full information of customer
     * mainly for testing
     */
    void printCustomer()const;
    /**
     * @brief getRobot1
     * @return
     * int of number of robot1's ordered
     */
    int getRobot1() const;
    /**
     * @brief getRobot2
     * @return
     * int of number of robot2's ordered
     */
    int getRobot2() const;
    /**
     * @brief getRobot3
     * @return
     * int of number of robot3's ordered
     */
    int getRobot3() const;
};

/**
 * @brief The customerlist class
 */
class customerlist {
private:
    QVector<customer> customers;
public:
    /**
     * @brief customerlist
     * default customerlist constructor, will get all customers from db
     */
    customerlist();

    customerlist(QString);
    /**
     * @brief getCustomer
     * @return
     * customer with name of passed QString
     */
    customer getCustomer(const QString&);
    /**
     * @brief addCustomer
     * add customer to list of customers
     */
    void addCustomer(const customer&);
    /**
     * @brief deleteCustomer
     * delete customer from list and database(soft delete)
     */
    void deleteCustomer(QString);
    /**
     * @brief printCustomers
     * print customers, not sure what to print so we will leave prototype for now
     */
    void printCustomers() const;
    /**
     * @brief printKeyCustomers
     * print key customers, not sure what to print so we will leave prototype for now
     */
    void printKeyCustomers() const;

    /**
     * @brief printToFile
     * print to file, not sure if we will need this
     */
    void printToFile() const;

    /**
     * @brief getCustomers
     * gets all the current customers
     * @return a vector of type customer
     */
    QVector<customer>getCustomers()const;

    /**
     * @brief FindCustomer
     * Finds a customer in the customer list
     * @param customerName
     * @returns a pointer of the customer or NULL if not found
     */
    customer *FindCustomer(QString customerName);

};

#endif
