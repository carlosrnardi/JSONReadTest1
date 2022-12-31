cmake_minimum_required(VERSION 3.14.5)

project(JSON_READ_TEST1 LANGUAGES CXX)

include(FetchContent)

add_subdirectory(external)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(LibExample)

target_include_directories(${PROJECT_NAME} PUBLIC LibExample)

#target_include_directories(${PROJECT_NAME} PUBLIC external/json/include)

target_link_directories(${PROJECT_NAME} PRIVATE LibExample)

target_link_libraries(${PROJECT_NAME} PRIVATE libexample nlohmann_json::nlohmann_json Boost::asio Boost::bind Boost::thread Boost::system)
