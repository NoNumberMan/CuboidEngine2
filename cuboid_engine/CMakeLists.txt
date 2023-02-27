#project
cmake_minimum_required (VERSION 3.8)
set(PROJECT_NAME cuboid_engine)
project(${PROJECT_NAME})

set(CUBOID_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../out/build/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}/)
set(CUBOID_GAME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../out/build/${CMAKE_BUILD_TYPE}/cuboid_game/)
set(GLFW_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../out/build/${CMAKE_BUILD_TYPE}/glfw/)

#sets
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#external
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../glfw/ ${GLFW_OUT_DIR})

#includes / linking
include_directories(${project_name}
    ${CMAKE_CURRENT_SOURCE_DIR}/../glfw/include/)

find_package(OpenGL REQUIRED)

#add exec
add_library (${PROJECT_NAME} SHARED "cuboid_engine.cpp" "cuboid_engine.h" "glad/glad.c"  "logger.cpp" "logger.h")

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CUBOID_OUT_DIR}cuboid_engine.dll ${CUBOID_GAME_DIR})