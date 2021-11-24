cmake_minimum_required(VERSION 3.12)

project(flex_bison_embedded VERSION 0.1.0
                  DESCRIPTION "Project to adapt flex/bison parser system to embedded applications"
                  LANGUAGES C)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(proof_of_concept)