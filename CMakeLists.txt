cmake_minimum_required(VERSION 3.0.0)
project(mytest VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(mytest main.cpp)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
add_subdirectory(mymath)
target_link_libraries(mytest PUBLIC mymath)

target_include_directories(mytest PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/mymath"
                          )
                          