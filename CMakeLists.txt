cmake_minimum_required (VERSION 3.0)

include_directories (include)

set(SRCS
    src/main.cpp
    src/Leap.cpp
    src/Mouse.cpp
    src/systray.cpp
)

message("-- Find packages")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_executable (leapmotion ${SRCS})

find_package(GTK2 2.10 REQUIRED gtk)
if(GTK2_FOUND)
   include_directories(${GTK2_INCLUDE_DIRS})
   target_link_libraries(leapmotion ${GTK2_LIBRARIES})
endif()

find_package(Leap)
if(LEAP_FOUND)
   include_directories(${LEAP_INCLUDE_DIRS})
   target_link_libraries(leapmotion ${LEAP_LIBRARIES})
endif()


target_link_libraries (leapmotion)

# Creates a folder "executables" and adds target
set_property(TARGET leapmotion PROPERTY FOLDER "executables")

# Adds logic to INSTALL.vcproj to copy app.exe to destination directory
install (TARGETS leapmotion
RUNTIME DESTINATION out)
