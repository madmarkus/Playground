project (experiment)

include_directories(../libMean)
add_executable(Experiment main.c)

target_link_libraries(Experiment mean)
