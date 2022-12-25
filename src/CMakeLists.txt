cmake_minimum_required(VERSION 3.22)

set(MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set (SOURCE
        main.cpp
        cart.cpp
        )
set (INCLUDE
       ${MY_DIRECTORY}/cart.h
        )

add_executable(page_title ${SOURCE} ${INCLUDE})

target_include_directories( page_title PUBLIC ${MY_DIRECTORY})