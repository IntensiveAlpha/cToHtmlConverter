cmake_minimum_required(VERSION 3.23)
project(todoist C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src/bstrlib)
add_compile_options(-Wall -Wextra -Werror -Wpedantic -lm -g)
pkg_add_module(GTK3 REQUIRED gtk+-3.0)
add_executable(todoist
        src/bstrlib/bstrlib.c
        src/bstrlib/bstrlib.h
        main.c)
