include(gtest_dependency.pri)

QT += core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
#CONFIG -= qt

HEADERS += \
        account.hpp \
        account_test.hpp \
        book.hpp \
        bookTest.hpp \
        cd.hpp \
        cdTest.hpp \
        collection.hpp \
        collectionTest.hpp \
        dvd.hpp \
        dvdTest.hpp \
        item.hpp \
        itemTest.hpp \
        tst_cdtest.h \
        user_items.hpp

SOURCES += \
        account.cpp \
        book.cpp \
        cd.cpp \
        collection.cpp \
        dvd.cpp \
        item.cpp \
        test.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
