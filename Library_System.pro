QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    accountwidget.cpp \
    adminpage.cpp \
    book.cpp \
    bookdialog.cpp \
    cd.cpp \
    cddialog.cpp \
    collection.cpp \
    collectiondialog.cpp \
    createAccountPage.cpp \
    dvd.cpp \
    dvddialog.cpp \
    item.cpp \
    libraryLogin.cpp \
    libraryitemfactory.cpp \
    libraryitemmodel.cpp \
    libraryitemproxymodel.cpp \
    libraryview.cpp \
    main.cpp \
    library.cpp \
    userprofiledialog.cpp

HEADERS += \
    account.hpp \
    accountwidget.h \
    adminpage.hpp \
    book.hpp \
    bookdialog.hpp \
    cd.hpp \
    cddialog.hpp \
    collection.hpp \
    collectiondialog.hpp \
    createAccountPage.hpp \
    dvd.hpp \
    dvddialog.hpp \
    item.hpp \
    library.hpp \
    libraryLogin.hpp \
    libraryitemfactory.hpp \
    libraryitemmodel.hpp \
    libraryitemproxymodel.hpp \
    libraryview.hpp \
    user_items.hpp \
    userprofiledialog.h

FORMS += \
    accountwidget.ui \
    adminpage.ui \
    bookdialog.ui \
    cddialog.ui \
    collectiondialog.ui \
    createAccountPage.ui \
    dvddialog.ui \
    library.ui \
    libraryLogin.ui \
    libraryview.ui \
    userprofiledialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
