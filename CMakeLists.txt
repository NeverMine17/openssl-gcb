cmake_minimum_required(VERSION 3.0)
project(openssl-gcb)

set(CMAKE_CXX_STANDARD 17)

link_libraries(crypto)
add_definitions("-O3 -Wall")

set(
        SOURCE_FILES
        base64.h base64.cpp gcm.h
        libgcb.cpp libgcb.h
)

add_library(
        openssl_gcb_file_encrypting SHARED ${SOURCE_FILES}
)
