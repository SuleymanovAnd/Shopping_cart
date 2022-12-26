cmake_minimum_required(VERSION 3.22)

set(MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set (SOURCE
        main.cpp
        cart.cpp
        )
set (INCLUDE
        ${MY_DIRECTORY}/cart.h
        ${MY_DIRECTORY}/exceptions.h
        )

add_executable(shopping_cart ${SOURCE} ${INCLUDE})

target_include_directories(shopping_cart PUBLIC ${MY_DIRECTORY})