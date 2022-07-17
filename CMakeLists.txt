cmake_minimum_required(VERSION 3.23.2)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
include(CheckIPOSupported)
check_ipo_supported(RESULT supported OUTPUT error)

project(project LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
    src/main.cpp
)

set_property(TARGET project PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lfmt
    # -fsanitize=address,undefined,leak
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Ofast
    -Wall -Wextra -Wpedantic -Wconversion
    # -fsanitize=address,undefined,leak
)
