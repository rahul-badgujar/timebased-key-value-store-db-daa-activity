cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main VERSION 1.0)

add_executable(
    main 
    main.cpp 
    src/exceptions/exception.cpp
    src/exceptions/no_update_history_found_exception.cpp
    src/console_io.cpp
    src/utility_functions.cpp
    )

target_include_directories(
    main 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )