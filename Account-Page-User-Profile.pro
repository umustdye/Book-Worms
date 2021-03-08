QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/account_page_user_profile.cpp \
    src/accountwidget.cpp \
    src/userprofiledialog.cpp \
    src/account.cpp \
    src/book.cpp \
    src/cd.cpp \
    src/collection.cpp \
    src/dvd.cpp \
    src/item.cpp \
    src/library.cpp \
    #
    src/test.cpp \

HEADERS += \
    header/account_page_user_profile.h \
    header/accountwidget.h \
    header/userprofiledialog.h \
    header/account.hpp \
    header/book.hpp \
    header/cd.hpp \
    header/collection.hpp \
    header/library.hpp \
    header/item.hpp \
    header/user_items.hpp \
    #
    tests/account_test.hpp \
    tests/bookTest.hpp \
    tests/cdTest.hpp \
    tests/collectionTest.hpp \
    tests/dvdTest.hpp \
    tests/itemTest.hpp \
    tests/library_test.hpp \

FORMS += \
    forms/account_page_user_profile.ui \
    forms/accountwidget.ui \
    forms/userprofiledialog.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
