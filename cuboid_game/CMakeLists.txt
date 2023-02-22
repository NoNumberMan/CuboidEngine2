#project
cmake_minimum_required (VERSION 3.8)
set(PROJECT_NAME cuboid_game)
project(${PROJECT_NAME})

set(CUBOID_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../out/build/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}/)
set(CUBOID_ENGINE_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../out/build/${CMAKE_BUILD_TYPE}/cuboid_engine/)

#sets
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CUBOID_OUT_DIR})

#includes / linking
include_directories(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/../cuboid_engine/
)

#add exec
add_executable (${PROJECT_NAME} "cuboid_game.cpp")

target_link_directories(${PROJECT_NAME}
    PRIVATE ${CUBOID_ENGINE_OUT_DIR})

target_link_libraries(${PROJECT_NAME}
    PRIVATE cuboid_engine)