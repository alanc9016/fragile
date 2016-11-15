#ifndef USER_H
#define USER_H
#include "mainwindow.h"

/**
* @brief badinputexception - custom exception class for login
*/
//class badinputexception{
//    QString errmsg;///< Error message
//public:
//    /**
//    * @brief badinputexception() - creates default badinputexception with generic error message
//    */
//    badinputexception();
//    /**
//    * @brief badinputexception(QString) - creates badinputexception with given error message
//    */
//    badinputexception(QString);
//    /**
//    * @brief getEx() - returns error message
//    */
//    QString getEx();
//};

/**
* @brief user - class for storing and verifying user logins
*/
class user{
    QString username; ///< Username of user
    QString password; ///< Password of user
    QString* valid; ///< Pointer to store validity of user

public:
    /**
     * @brief user - default user
     */
    user();

    /**
     * @brief destructor
     * */
    ~user();

    /**
     * @brief user - sets username and password to a user
     */
    user(QString, QString);

    /**
     * @brief user
     * copy constructor
     */
    user(const user&);

    /**
     * @brief getUsername - gets username of a user
     * @return - username
     */
    QString getUsername();

    /**
     * @brief setUsername - set username of a user
     */
    void setUsername(QString);

    /**
     * @brief getPassword - gets password of a user
     * @return - password
     */
    QString getPassword();

    /**
     * @brief setPassword - sets password of a user
     */
    void setPassword(QString);

    /**
     * @brief getUserType - gets usertype: Executive or Regular
     * @return - usertype
     */
    QString* getValid();

    /**
     * @brief setUserType - sets user type: Executive or Regular
     */
    void setValid(QString*);

    /**
     * @brief elevation - Determines which main menu to display
     * @return
     */
    virtual bool elevation();
    /**
     * @brief ex -
     */
    //badinputexception ex;///< custom exception class, makes user class a composition
};

class admin: public user{
public:
    /**
     * @brief admin
     * copy constructor for use on base class object
     */
    admin(user&);

    /**
     * @brief elevation - Determines which main menu to display
     * @return
     */
    virtual bool elevation();
};

#endif // USER_H
