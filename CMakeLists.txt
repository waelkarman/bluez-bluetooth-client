cmake_minimum_required(VERSION 3.16)

project(bt_dbus_service)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED gio-2.0 glib-2.0 gobject-2.0)
include_directories(${GLIB_INCLUDE_DIRS})

set(SOURCES
    bt_dbus_service.cpp
)

set(HEADERS
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} 
    ${GLIB_LIBRARIES}
)

