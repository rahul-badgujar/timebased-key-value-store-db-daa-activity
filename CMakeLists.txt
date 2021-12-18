cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main VERSION 1.0)

add_executable(
    main 
    main.cpp 
    src/exception.cpp
    src/no_update_history_found_exception.cpp
    )

target_include_directories(
    main 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )