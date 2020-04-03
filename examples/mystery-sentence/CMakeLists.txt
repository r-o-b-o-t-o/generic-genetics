CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(example_mystery_sentence)
SET(CMAKE_CXX_STANDARD 17)

ADD_SUBDIRECTORY("${PROJECT_SOURCE_DIR}/../.." "bin_genericgenetics")

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

ADD_EXECUTABLE(
    example_mystery_sentences

    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/crossover.cpp
    ${PROJECT_SOURCE_DIR}/src/evaluator.cpp
    ${PROJECT_SOURCE_DIR}/src/generator.cpp
    ${PROJECT_SOURCE_DIR}/src/mutation.cpp
)

IF (CMAKE_COMPILER_IS_GNUCC)
    TARGET_COMPILE_OPTIONS(example_mystery_sentences PRIVATE "-Wall")
ENDIF ()
IF (MSVC)
    TARGET_COMPILE_OPTIONS(example_mystery_sentences PRIVATE "/W4")
ENDIF ()
