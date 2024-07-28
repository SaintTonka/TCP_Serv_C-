cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)


cmake_policy(SET CMP0144 NEW) 

set(Boost_ROOT "Z:/boost_1_85_0")

find_package(Boost 1.85 REQUIRED)

add_library(Network STATIC 
    src/Base.cpp
    src/tcp_connection.cpp
    include/Networki/BaseServ.h
    include/Networki/tcp_connection.h
)

target_include_directories(Network PUBLIC 
    ${CMAKE_SOURCE_DIR}/Networking/include
    ${Boost_INCLUDE_DIRS} 
)

target_link_libraries(Network PRIVATE 
    ${Boost_LIBRARIES}
)