#include "libraryLogin.h"
#include "ui_libraryLogin.h"
#include "account.h"
#include "createAccountPage.h"

#include <QDebug>


LibraryLogin::LibraryLogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibraryLogin)
{
    ui->setupUi(this);
    //TEST THE ACCOUNT CLASS!
    QString userName = "username";
    QString password = "password";
    QString firstName = "Some";
    QString lastName = "Person";
    int id = 1;
    AccountType accountType= admin;
    Account account(userName, password, firstName, lastName, id, accountType);
    qDebug() << account.getAccountType();
    //------------------------------------------------------------------------------------
    ui->inputMessage->hide();
    //Set up password field
    ui->passwordInput->setEchoMode(QLineEdit::Password);
    //ui->passwordInput->passwordMaskDelay();


}

LibraryLogin::~LibraryLogin()
{
    delete ui;
}


void LibraryLogin::on_loginButton_clicked()
{
    //check if the user is in the database
    QString message = "";

    /*
    //if the account does not exist
    message = "Account Does Not Exist";

    //if the password is incorrect
    message = "Password is Incorrect";
    */




    if(connectToAccountDB())
    {
        //get the values from the form
        QString userName = ui->userNameInput->text();
        QString password = ui->passwordInput->text();




        //if the login is successful
        if(validLogin(userName, password))
        {
            message = "Login Successful";

            //get the values from the database and save into User item
            loadAccount(userName, password);




            /*
            //go to the appropriate login page
            if(user)
            {
                //go to user page
            }

            else
            {
                //go to admin page
            }
            */
        }

        //if the login was not in the database
        else
        {
            message = "Account does not exist";
        }

        //close database connection
        db.close();

    }

    //could not connect to the database
    else
    {
        message = "Could not login into the system";
    }

    changeInputMessage(message);
}

void LibraryLogin::on_createAccountButton_clicked()
{
    //load create account dialog
    CreateAccountPage createAccountPage;
    createAccountPage.exec();
}

void LibraryLogin::changeInputMessage(const QString &iconText)
{
    //error message change text
    ui->inputMessage->setText(iconText);
    ui->inputMessage->show();

}


bool LibraryLogin::connectToAccountDB()
{
    //connect to DB driver
    db = QSqlDatabase::addDatabase("QSQLITE");
    //database name
    QString dbName = "Account.db3";
    //try to connect to database
    db.setDatabaseName(dbName);
    db.open();
    //if we are able to connected into the database
    if(db.isOpen())
    {
        qDebug() << "Successfully connected to the database";
        //set a new query
        QSqlQuery query = QSqlQuery(db);
        //create account table if it does not exist
        query.exec( "CREATE TABLE IF NOT EXISTS account ( id INTEGER PRIMARY KEY AUTOINCREMENT, userName TEXT, password TEXT, firstName TEXT, lastName TEXT, accountType INTEGER )" );
        return true;

    }

    else
    {
        //account could not be added
        qDebug() << "Could not connect to database";
        return false;
    }

}

bool LibraryLogin::validLogin(QString userName, QString password)
{
    //check the database to see if the username exists
    QSqlQuery query = QSqlQuery(db);
    query.prepare("SELECT password FROM account WHERE userName = ?");
    query.addBindValue(userName);

    query.exec();

    //if the user does not exist
    if(query.first() == false)
    {
        qDebug() << "Account DNE";
        return false;
    }
    //if the user exists
    else
    {
        QString dbPassword = query.value(0).toString();
        if(dbPassword != password)
        {
            return false;
        }

    }


    //username and password exist
    return true;
}


void LibraryLogin::loadAccount(QString userName, QString password)
{
    //check the database to see if the username exists
    QSqlQuery query = QSqlQuery(db);
    query.prepare("SELECT * FROM account WHERE userName = ?");
    query.addBindValue(userName);

    bool success = query.exec();
    qDebug() << success;
    query.first();
    int indexNo = query.record().indexOf("id");
    int firstNo = query.record().indexOf("firstName");
    int lastNo = query.record().indexOf("lastName");
    int typeNo = query.record().indexOf("accountType");
    int id = query.value(indexNo).toInt();
    QString firstName = query.value(firstNo).toString();
    QString lastName = query.value(lastNo).toString();
    int accountTypeInt = query.value(typeNo).toInt();
    AccountType accountType = admin;

    switch(accountTypeInt)
    {
        case 0:
            accountType = user;
            break;
        case 1:
            accountType = admin;
            break;
        default:
            accountType = user;
            break;

    };
    qDebug() << id;
    qDebug() << userName;
    qDebug() << password;
    qDebug() << firstName;
    qDebug() << lastName;
    qDebug() << accountTypeInt;
    qDebug() << accountType;

    //save in user object
}
