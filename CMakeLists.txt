CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(main
    src/main.cpp
    src/communicator.cpp
    src/coordinator.cpp
    src/mock_library_item_component.cpp
    src/mock_user_account.cpp
)

ADD_EXECUTABLE(test
        tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
