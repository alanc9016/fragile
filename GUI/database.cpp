#include "mainwindow.h"
/**
 * @brief createDatabase
 * Creates the SQLite database if there isn't one
 */
void createDatabase()
{
    QDir current = QDir(QString("./"));
    QString filenames [3] = {current.currentPath().remove(QRegExp("build.+")),
                             current.currentPath().remove(QRegExp("build.+")),
                             current.currentPath().remove(QRegExp("build.+"))
                            };
    filenames[0].append("irobots.db");
    filenames[1].append("createdb.sql");
    filenames[2].append("data.sql");

    //Check if database exists before we init it
    QFileInfo check_file(filenames[0]);
    bool exists = check_file.exists() && check_file.isFile();

    // connect to database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filenames[0]);
    bool db_ok = db.open();
     QTextStream(stdout) << "Connecting to database" << endl;
    if(db_ok){
        QTextStream(stdout) << "All good" << endl;
    }

    //If the database doesn't exist, run the init queries
    if(!exists) {
        executeSQLFile(filenames[1]);
        executeSQLFile(filenames[2]);
    }
    QTextStream(stdout) << filenames[0] << endl;
    QTextStream(stdout) << filenames[1] << endl;
    QTextStream(stdout) << filenames[2] << endl;
}
/**
 * @brief executeSQLFile
 * Will execute pre-made .sql files in order to create the database
 * @param file - the relative path to the .sql file
 */
void executeSQLFile(const QString &file){
    QSqlQuery query2;
    QFile fp(file);
    fp.open(QFile::ReadOnly|QFile::Text);
    QTextStream(stdout) << "Executing file: " << file;

    //Read in entire sql file
    QString q = fp.readAll();

    //Split each query into its own string
    QStringList queries = q.split(';');
    foreach (QString query, queries)
    {
        //Execute the induvidual query
        bool ret = query2.exec(query);

        if(!ret) {
             QTextStream(stdout) << query;
             QTextStream(stdout) << query2.lastError().text();
        }

        //Reset the query
        query2.finish();
    }
}

