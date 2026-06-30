cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)

project(ChatRPC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMMON_SRC
    chat.cpp
    chat.h
    utils.cpp
    utils.h
    user.h
)

add_executable(server
    ${COMMON_SRC}
    server.cpp
    clientManager.cpp
    clientManager.h
    user.cpp
)

target_link_libraries(server pthread)

add_executable(client
    ${COMMON_SRC}
    main.cpp
    userDistribuido.cpp
)

target_link_libraries(client pthread)
