cmake_minimum_required (VERSION 2.6)
project (experiment)

add_subdirectory(libMean)
add_subdirectory(program)

add_dependencies(Experiment mean)
