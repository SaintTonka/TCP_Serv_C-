cmake_minimum_required(VERSION 3.15.0)

project(SERVER)

cmake_policy(SET CMP0144 NEW) 


include_directories(${CMAKE_SOURCE_DIR}/Networking/include)
set(BOOST_ROOT "Z:/boost_1_85_0") 
find_package(Boost REQUIRED) 
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(Networking)
add_subdirectory(client)
add_subdirectory(server)
