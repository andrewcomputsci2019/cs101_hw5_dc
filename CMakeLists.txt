cmake_minimum_required(VERSION 3.20)

project(dc_imperical_show VERSION 1 LANGUAGES C)

find_package(SmartPointer CONFIG REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME}_${PROJECT_VERSION}.out)

set(TARGET ${PROJECT_NAME}_${PROJECT_VERSION}.out PROPERTY C_STANDARD 11)

set(sources_list ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c ${CMAKE_CURRENT_SOURCE_DIR}/src/sol.c)

target_sources(${PROJECT_NAME}_${PROJECT_VERSION}.out PUBLIC ${sources_list})

target_include_directories(${PROJECT_NAME}_${PROJECT_VERSION}.out PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)
target_link_libraries(${PROJECT_NAME}_${PROJECT_VERSION}.out SmartPointer::SmartPointer)
