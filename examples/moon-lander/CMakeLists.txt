CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(example_moon_lander)
SET(CMAKE_CXX_STANDARD 17)

ADD_SUBDIRECTORY("${PROJECT_SOURCE_DIR}/../.." "bin_genericgenetics")

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

ADD_EXECUTABLE(
    example_moon_lander

    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

FIND_PACKAGE(SFML 2 REQUIRED graphics window system)
IF (SFML_FOUND)
    INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(example_moon_lander sfml-graphics sfml-window sfml-system)
ENDIF ()
