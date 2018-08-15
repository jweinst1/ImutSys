cmake_minimum_required(VERSION 3.5)

project(Copper)

######Warlock core source files#######
SET(core_files
    src/Copper.c
    src/copper_make.c
)

####### Copper Libraries ########

add_library(CopperShared SHARED 
    "${core_files}"
)

add_library(CopperStatic STATIC 
    "${core_files}"
)

###################################

target_include_directories(CopperStatic
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(CopperShared
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# Add test executables to build
add_executable(CopperTests
    tests/test_main.c
)

target_include_directories(CopperTests
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# links library to test executable
target_link_libraries( CopperTests
    PRIVATE 
        CopperShared
)
