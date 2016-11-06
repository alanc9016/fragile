#ifndef CUSTOMER
#define CUSTOMER
#include "mainwindow.h"
class customer
{
private:
    QString name;///> Name of Customer
    QString street;///> Street Address of Customer
    QString city;///> City of Customer
    QString state;///> State (postal) of Customer
    int	zip;///> Zip code of Customer
    QString status;///> Status of Customer (key or nice to have)
    QString testimonial;///> Testimonial of Customer (default null)
    QString requested;///> Status of requested pamphlet by customer
    bool isActive;///> 1 active, 0 inactive or deleted
public:
    customer():
        name("Default"),
        street("123 Default Way"),
        city("Default City"),
        state("DS"),
        zip(12345),
        status("default"),
        testimonial("default testimonial"),
        requested("not requested"),
        isActive(true)
    {}
    customer(QString, QString, QString, QString, int, QString, QString, QString) {

    }
};

#endif
