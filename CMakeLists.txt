cmake_minimum_required(VERSION 3.0)
project(openssl-gcb)

set(CMAKE_CXX_STANDARD 11)

link_libraries(crypto)
add_definitions("-O3 -Wall")

set(
        SOURCE_FILES
        base64.h base64.cpp gcm.h
        libgcb.cpp libgcb.h
)

add_library(
        openssl-gcb SHARED ${SOURCE_FILES}
)
