CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(generic_genetics)
SET(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

ADD_EXECUTABLE(
    genericgenetics

    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/random.cpp
    ${PROJECT_SOURCE_DIR}/src/MyGenerator.cpp
    ${PROJECT_SOURCE_DIR}/src/MyEvaluator.cpp
    ${PROJECT_SOURCE_DIR}/src/MyCrossover.cpp
)
