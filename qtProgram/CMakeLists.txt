project (QtProgram)

FIND_PACKAGE(Qt4 REQUIRED)

SET(qtProgram_SOURCES gui.cpp finddialog.cpp)
SET(qtProgram_HEADERS finddialog.h)

# Notice that the headers only include the headers that needs to be processed by moc. 
# All other headers can be left out of the CMakeLists.txt file. This also implicates 
# that if you add a Q_OBJECT macro to any of your classes you must ensure that it is listed here.
# see http://developer.qt.nokia.com/quarterly/view/using_cmake_to_build_qt_projects

# To invoke moc, the macro QT4_WRAP_CPP is used. It assigns the names of the resulting 
# files to the variable listed first. In this case the line looks as follows.
QT4_WRAP_CPP(qtProgram_HEADERS_MOC ${qtProgram_HEADERS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

include_directories(../libMean)

add_executable(QtProgram ${qtProgram_SOURCES} ${qtProgram_HEADERS_MOC})

target_link_libraries(QtProgram mean ${QT_LIBRARIES})
