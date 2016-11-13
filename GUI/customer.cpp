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
    isActive(true),
    robot1(0),
    robot2(0),
    robot3(0)
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
customer::customer(QString a, QString b , QString c, QString d, QString e, QString f, QString g, QString h, QString i,
                   int r1, int r2, int r3):
    name(a), street(b), city(c), state(d), zip(e), status(f), interest(g), testimonial(h), requested(i), isActive(true),
    robot1(r1), robot2(r2),robot3(r3)
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
    testimonial(""), requested("not requested"), isActive(true),robot1(0),robot2(0),robot3(0)
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
 * @brief customer::getRobot1
 * @return
 * amount of robot1's ordered
 */
int customer::getRobot1() const
{
    return robot1;
}
/**
 * @brief customer::getRobot2
 * @return
 * amount of robot2's ordered
 */
int customer::getRobot2() const
{
    return robot2;
}
/**
 * @brief customer::getRobot3
 * @return
 * amount of robot3's ordered
 */
int customer::getRobot3() const
{
    return robot3;
}

/**
 * @brief customer::setName
 * @param n
 * the value name will be set to
 */
void customer::setName(QString n)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET name='"+n+"' where name='"+name+"'");
    name = n;
}

/**
 * @brief customer::setStreet
 * @param s
 * the value street will be set to
 */
void customer::setStreet(QString s)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET street='"+s+"' where name='"+name+"'");
    street = s;
}

/**
 * @brief customer::setCity
 * @param c
 * the value city will be set to
 */
void customer::setCity(QString c)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET city='"+c+"' where name='"+name+"'");
    city = c;
}

/**
 * @brief customer::setState
 * @param s
 * the value state will be set to
 */
void customer::setState(QString s)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET state='"+s+"' where name='"+name+"'");
    state = s;
}

/**
 * @brief customer::setZip
 * @param z
 * the value zip will be set to
 */
void customer::setZip(QString z)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET zip='"+z+"' where name='"+name+"'");
    zip = z;
}

/**
 * @brief customer::setStatus
 * @param s
 * the value status will be set to
 */
void customer::setStatus(QString s)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET status='"+s+"' where name='"+name+"'");
    status = s;
}

/**
 * @brief customer::setInterest
 * @param i
 * the value interest will be set to
 */
void customer::setInterest(QString i)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET interest='"+i+"' where name='"+name+"'");
    interest = i;
}

/**
 * @brief customer::setTestimonial
 * @param t
 * the value testimonial will be set to
 */
void customer::setTestimonial(QString t)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET testimonial='"+t+"' where name='"+name+"'");
    testimonial = t;
}

/**
 * @brief customer::setRequested
 * @param r
 * the value requested will be set to
 */
void customer::setRequested(QString r)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET requested='"+r+"' where name='"+name+"'");
    requested = r;
}

/**
 * @brief customer::setActive
 * @param a
 * the value isActive will be set to
 */
void customer:: setActive(bool a)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET isActive='"+QString::number(a)+"' where name='"+name+"'");
    isActive = a;
}

/**
 * @brief customer::setRobot1
 * @param r
 */
void customer::setRobot1(int r)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET robot1='"+QString::number(r)+"' where name='"+name+"'");
    robot1 = r;
}
/**
 * @brief customer::setRobot2
 * @param r
 */
void customer::setRobot2(int r)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET robot2='"+QString::number(r)+"' where name='"+name+"'");
    robot2 = r;
}
/**
 * @brief customer::setRobot3
 * @param r
 */
void customer::setRobot3(int r)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET robot3='"+QString::number(r)+"' where name='"+name+"'");
    robot3 = r;
}

