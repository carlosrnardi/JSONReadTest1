cmake_minimum_required(VERSION 3.13.4)

project(JSON_READ_TEST1)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(LibExample)

target_include_directories(${PROJECT_NAME} PUBLIC LibExample)

target_link_directories(${PROJECT_NAME} PRIVATE LibExample)

target_link_libraries(${PROJECT_NAME} libexample)