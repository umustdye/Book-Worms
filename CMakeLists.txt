CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)
INCLUDE_DIRECTORIES(header)
INCLUDE_DIRECTORIES(tests)

ADD_EXECUTABLE(test
    tests/test.cpp
    src/account.cpp
    src/library.cpp
    src/cd.cpp
    src/book.cpp
    src/dvd.cpp
    src/item.cpp
    src/collection.cpp
    src/account.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
