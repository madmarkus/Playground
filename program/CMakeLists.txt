cmake_minimum_required (VERSION 2.6)

project (experiment)

add_executable(Experiment main.c)

target_link_libraries(Experiment mean)
