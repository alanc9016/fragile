#include "customer.h"
/**
 * @brief customer
 * Default constructor/never stored in db
 */
customer::customer():
    name("Default"),
    street("123 Default Way"),
    city("Default City"),
    state("DS"),
    zip("12345"),
    status("default"),
    interest("default"),
    testimonial("default testimonial"),
    requested("not requested"),
    isActive(true)
{}
/**
 * @brief customer
 * Constructor with all parameters except isActive, that is asssumed true
 * @param a
 * name will be set to a
 * @param b
 * street will be set to b
 * @param c
 * city will be set to c
 * @param d
 * state will be set to d
 * @param e
 * zip will be set to e
 * @param f
 * status will be set to f
 * @param g
 * interest will be set to g
 * @param h
 * testimonial will be set to h
 * @param i
 * requested will be set to i
 */
customer::customer(QString a, QString b , QString c, QString d, QString e, QString f, QString g, QString h, QString i):
    name(a), street(b), city(c), state(d), zip(e), status(f), interest(g), testimonial(h), requested(i), isActive(true)
{}

/**
 * @brief customer
 * Customer with name and address passed, likely to be the most used
 * @param nm
 * name will be set to nm
 * @param str
 * street will be set to str
 * @param cty
 * city will be set to cty
 * @param sta
 * state will be set to sta
 * @param zp
 * zip will be set to zp
 */
customer::customer(QString nm, QString str, QString cty, QString sta, QString zp):
    name(nm), street(str), city(cty), state(sta), zip(zp), status("nice to have"), interest("somewhat interested"),
    testimonial(""), requested("not requested"), isActive(true)
{}

/**
 * @brief customer::getName
 * @return
 * name as QString
 */
QString customer::getName() const
{
    return name;
}

/**
 * @brief customer::getStreet
 * @return
 * street as QString
 */
QString customer::getStreet() const
{
    return street;
}

/**
 * @brief customer::getCity
 * @return
 * city as QString
 */
QString customer::getCity() const
{
    return city;
}

/**
 * @brief customer::getState
 * @return
 * state (postal) as QString
 */
QString customer::getState() const
{
    return state;
}

/**
 * @brief customer::getZip
 * @return
 * zipcode as int
 */
QString customer::getZip() const

{
    return zip;
}

/**
 * @brief customer::getStatus
 * @return
 * status of customer as QString
 */
QString customer::getStatus() const
{
    return status;
}

/**
 * @brief customer::getInterest
 * @return
 * interest as QString
 */
QString customer::getInterest() const
{
    return interest;
}

/**
 * @brief customer::getTestimonial
 * @return
 * testimonial of customer as QString
 */
QString customer::getTestimonial() const
{
    return testimonial;
}

/**
 * @brief customer::getRequested
 * @return
 * the request status of customer as QString
 */
QString customer::getRequested() const
{
    return requested;
}

/**
 * @brief customer::getActive
 * @return
 * active(true) or inactive(false)
 */
bool customer::getActive() const
{
    return isActive;
}

/**
 * @brief customer::setName
 * @param n
 * the value name will be set to
 */
void customer::setName(QString n)
{
    name = n;
}

/**
 * @brief customer::setStreet
 * @param s
 * the value street will be set to
 */
void customer::setStreet(QString s)
{
    street = s;
}

/**
 * @brief customer::setCity
 * @param c
 * the value city will be set to
 */
void customer::setCity(QString c)
{
    city = c;
}

/**
 * @brief customer::setState
 * @param s
 * the value state will be set to
 */
void customer::setState(QString s)
{
    state = s;
}

/**
 * @brief customer::setZip
 * @param z
 * the value zip will be set to
 */
void customer::setZip(QString z)
{
    zip = z;
}

/**
 * @brief customer::setStatus
 * @param s
 * the value status will be set to
 */
void customer::setStatus(QString s)
{
    status = s;
}

/**
 * @brief customer::setInterest
 * @param i
 * the value interest will be set to
 */
void customer::setInterest(QString i)
{
    interest = i;
}

/**
 * @brief customer::setTestimonial
 * @param t
 * the value testimonial will be set to
 */
void customer::setTestimonial(QString t)
{
    testimonial = t;
}

/**
 * @brief customer::setRequested
 * @param r
 * the value requested will be set to
 */
void customer::setRequested(QString r)
{
    requested = r;
}

/**
 * @brief customer::setActive
 * @param a
 * the value isActive will be set to
 */
void customer:: setActive(bool a)
{
    isActive = a;
}
