cmake_minimum_required(VERSION 3.16)

project(VIRUS LANGUAGES CXX)

find_package(CURL REQUIRED)

include_directories(/usr/include/dpp)
link_directories(/usr/lib)

add_executable(${PROJECT_NAME} main.cpp network.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl dpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
