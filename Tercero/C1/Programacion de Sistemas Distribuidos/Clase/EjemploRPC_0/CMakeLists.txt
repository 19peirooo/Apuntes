 
cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)

project(server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server utils.h utils.cpp server.cpp persona.h persona.cpp clientManager.h clientManager.cpp)
target_link_libraries(server pthread)


project(client LANGUAGES CXX)
add_executable(client utils.h utils.cpp main.cpp persona.h personaDistribuida.cpp)
target_link_libraries(client pthread)

project(persona LANGUAGES CXX)
add_executable(persona persona.h persona.cpp main.cpp)
target_link_libraries(persona pthread)









