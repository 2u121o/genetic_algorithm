cmake_minimum_required(VERSION 3.5)

project(genetic_algorithm)

set(CMAKE_BUILD_TYPE Release)

set(genetic_algorithm_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)

set(SOURCES 
            ${PROJECT_SOURCE_DIR}/src/GACore.cpp
            ${PROJECT_SOURCE_DIR}/src/Genome.cpp
            ${PROJECT_SOURCE_DIR}/src/Population.cpp
    )

include_directories(${genetic_algorithm_INCLUDE_PATH})

add_library(${PROJECT_NAME} SHARED ${SOURCES})