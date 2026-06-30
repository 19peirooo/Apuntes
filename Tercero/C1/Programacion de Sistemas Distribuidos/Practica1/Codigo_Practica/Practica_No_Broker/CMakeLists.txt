# Víctor Manuel Peiró Martínez
cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)

project(FileManagerDist LANGUAGES CXX)

add_library(FileManager STATIC IMPORTED) 
set_target_properties(FileManager PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libFileManager.a"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMMON_SRC
    utils.cpp
    utils.h
    filemanager.h
    server.h
)

add_executable(server
    ${COMMON_SRC}
    server.cpp
)

target_link_libraries(server pthread FileManager stdc++fs)

add_executable(client
    ${COMMON_SRC}
    main_fm.cpp
    fileManagerDistribuido.cpp
)

target_link_libraries(client pthread stdc++fs)
