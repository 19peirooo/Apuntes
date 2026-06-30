cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)

project(FileManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMMON_SRC
    utils.cpp
    utils.h
    filemanager.h
    server.h
    broker.h
)

add_executable(server
    ${COMMON_SRC}
    server.cpp
    filemanager.cpp
)

target_link_libraries(server pthread stdc++fs)

add_executable(client
    ${COMMON_SRC}
    main_fm.cpp
    fileManagerDistribuido.cpp
)

target_link_libraries(client pthread stdc++fs)

add_executable(broker
    utils.cpp
    utils.h
    broker.h
    broker.cpp
)

target_link_libraries(broker pthread stdc++fs)