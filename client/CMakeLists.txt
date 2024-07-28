cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)

add_executable(client_main client_main.cpp)

# Link the Networking library
target_link_libraries(client_main PRIVATE Network)

# Include directories for client
target_include_directories(client_main PRIVATE ${CMAKE_SOURCE_DIR}/Networking/include)
