#include "header/libraryLogin.hpp"
#include "ui_libraryLogin.h"
#include "header/account.hpp"
#include "header/createAccountPage.hpp"

#include <QDebug>


LibraryLogin::LibraryLogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibraryLogin)
{
    ui->setupUi(this);

    ui->inputMessage->hide();
    //Set up password field
    ui->passwordInput->setEchoMode(QLineEdit::Password);
    //ui->passwordInput->passwordMaskDelay();

    //setStackWidget();
}

LibraryLogin::~LibraryLogin()
{
    delete ui;
    delete account;
}


void LibraryLogin::on_loginButton_clicked()
{
    //check if the user is in the database
    QString message = "";

    if(connectToAccountDB())
    {
        //get the values from the form
        QString userName = ui->userNameInput->text();
        QString password = ui->passwordInput->text();




        //if the login is successful
        message = validLogin(userName, password);



        //get the values from the database and save into User item
        if(message == "Login Successful")
        {
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
    QString dbName = "/home/chris/Documents/databases/account (copy).db3";
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

QString LibraryLogin::validLogin(QString userName, QString password)
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
        return "Username does not exist";
    }
    //if the user exists
    else
    {
        QString dbPassword = query.value(0).toString();
        if(dbPassword != password)
        {
            return "Password is incorrect";
        }

    }

    //username and password exist
    return "Login Successful";
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
    int itemsNo = query.record().indexOf("items");
    int id = query.value(indexNo).toInt();
    QString firstName = query.value(firstNo).toString();
    QString lastName = query.value(lastNo).toString();
    int accountTypeInt = query.value(typeNo).toInt();
    AccountType accountType = admin;
    QByteArray byteArray = query.value(itemsNo).toByteArray();
    QVector<userItems> items;
    if(!byteArray.isEmpty())
    {
        //parse QByteArray into vector
        items = parseObject(byteArray);
    }

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

    for (int i=0; i<items.count(); i++)
    {
        qDebug() << items[i].id;
        qDebug() << items[i].quantity;
        qDebug() << items[i].dueDate;
        account->addItem(items[i]);
    }

    // store database values in account object
    account->setUserName(userName);
    account->setPassword(password);
    account->setFirstName(firstName);
    account->setLastName(lastName);
    account->setAccountType(accountType);
    account->setId(accountTypeInt);

    qDebug() << account->getUserName();
    qDebug() << account->getPassword();
    qDebug() << account->getFirstName();
    qDebug() << account->getLastName();
    qDebug() << account->getAccountType();
    qDebug() << account->getId();

    items = account->getItemVector();

    for (int i=0; i<items.count(); i++)
    {
        qDebug() << items[i].id;
        qDebug() << items[i].quantity;
        qDebug() << items[i].dueDate;
    }
}


//void LibraryLogin::setStackWidget() {
//    QWidget *libraryPageWidget = new QWidget;

//    QStackedWidget *libraryStackedWidget = new QStackedWidget;
//    libraryStackedWidget->addWidget(libraryPageWidget);

//    QVBoxLayout *stackLayout = new QVBoxLayout;
//    stackLayout->addWidget(libraryStackedWidget);
//    setLayout(stackLayout);

//    QComboBox *pageComboBox = new QComboBox;
//    pageComboBox->addItem(tr("Page 1"));

//    connect(pageComboBox, QOverload<int>::of(&QComboBox::activated),
//            libraryStackedWidget, &QStackedWidget::setCurrentIndex);

//    pageComboBox->setCurrentIndex(0);
//}


QVector<userItems> LibraryLogin::parseObject(QByteArray byteArray)
{
    QVector<userItems> items;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);
    QJsonArray jsonArray = jsonDoc.array();
    for (int i=0; i<jsonArray.count(); i++)
    {
        QJsonObject obj = jsonArray[i].toObject();

        int id = obj["id"].toInt();
        int quantity = obj["quantity"].toInt();
        QString dueDateStr = obj["dueDate"].toString();
        QDateTime dueDate = QDateTime::fromString(dueDateStr, "ddd MMMM d yyyy h:m ap");
        userItems item;
        item.id = id;
        item.quantity = quantity;
        item.dueDate = dueDate;
        items.push_back(item);
    }

    return items;
}