﻿cmake_minimum_required(VERSION 3.24)

project(ComputerClub
    LANGUAGES CXX
    VERSION 1.0.0
    HOMEPAGE_URL "https://github.com/Mistral5/ComputerClub"
)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory("bin")
add_subdirectory("include")
add_subdirectory("src")

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Lib)

enable_testing()
add_subdirectory("tests")

# includes
set(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}Lib ${PROJECT_NAME}Tests)
foreach(target IN LISTS TARGETS)
    target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
endforeach()
