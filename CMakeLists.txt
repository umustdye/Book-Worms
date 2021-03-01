CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)
INCLUDE_DIRECTORIES(header)

ADD_EXECUTABLE(test
    tests/test.cpp
    src/user.cpp
    src/admin.cpp
    src/library.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
