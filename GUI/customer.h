#ifndef CUSTOMER
#define CUSTOMER
#include "mainwindow.h"
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
    customer(QString, QString, QString, QString, QString, QString, QString, QString, QString);
    /**
     * @brief customer
     * Customer constructor that will take name and address. Will most likely be used
     */
    customer(QString, QString, QString, QString, QString);
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
     * @brief readDB
     * read from database file and add to list
     */
    void readDB();
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
};

#endif
