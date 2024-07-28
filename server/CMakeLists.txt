cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)

add_executable(server_main server_main.cpp)

# Link the Networking library
target_link_libraries(server_main PRIVATE Network)

target_include_directories(server_main PRIVATE ${CMAKE_SOURCE_DIR}/Networking/include)


