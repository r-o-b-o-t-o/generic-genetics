CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(example_moon_lander)
SET(CMAKE_CXX_STANDARD 17)

ADD_SUBDIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/../.." "bin_genericgenetics")

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/lib")

ADD_EXECUTABLE(
    example_moon_lander

    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/map.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lander.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/texture_loader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bot_lander.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mutation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/crossover.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/generator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/evaluator.cpp
)

FIND_PACKAGE(SFML 2 REQUIRED graphics window system)
IF (SFML_FOUND)
    INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(example_moon_lander sfml-graphics sfml-window sfml-system)
ENDIF ()

ADD_CUSTOM_COMMAND(TARGET example_moon_lander POST_BUILD COMMAND "${CMAKE_COMMAND}" -E rm -rf ${CMAKE_BINARY_DIR}/resources DEPENDS example_moon_lander)
ADD_CUSTOM_COMMAND(TARGET example_moon_lander POST_BUILD COMMAND "${CMAKE_COMMAND}" -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources DEPENDS example_moon_lander)

IF (CMAKE_COMPILER_IS_GNUCC)
    TARGET_COMPILE_OPTIONS(example_moon_lander PRIVATE "-Wall")
ENDIF ()
IF (MSVC)
    TARGET_COMPILE_OPTIONS(example_moon_lander PRIVATE "/W4")
ENDIF ()
