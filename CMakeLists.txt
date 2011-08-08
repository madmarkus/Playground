cmake_minimum_required (VERSION 2.8)
project (experiment)

add_subdirectory(libMean)
add_subdirectory(program)
add_subdirectory(qtProgram)

add_dependencies(Experiment mean)
