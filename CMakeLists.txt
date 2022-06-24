cmake_minimum_required(VERSION 3.13)
set(PROJECT_ID image_processor__skeleton)

<<<<<<< Updated upstream
=======
project(${PROJECT_ID})

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion)

if (WIN32)
    add_compile_options(-Wno-multichar)
endif (WIN32)

include_directories(include)

>>>>>>> Stashed changes
set(SOURCE_FILES
        src/bitmap.c
        src/improc.cpp
        src/imqueue.cpp)

set(SOURCES_FILES_TEST
        test/main_gtest.cpp)

set(GTEST_ROOT
        D:/ProgramData/CLion/agh/mdig-agh-lang_cpp__exercises__en-b8fe6a7ea81f/googletest-master)

project(${PROJECT_ID})

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion)

<<<<<<< Updated upstream
if (WIN32)
    add_compile_options(-Wno-multichar)
endif (WIN32)
=======
    # Przyjmij, że główny katalog z plikami frameworku GTF znajduje się
    # dwa katalogi wyżej względem katalogu projektu.
    set(GTEST_ROOT /users/erneststrychalski/googletest-master)
>>>>>>> Stashed changes

include_directories(include)

add_executable(image_processor__debug ${SOURCE_FILES} main.c)

add_executable(image_processor__test ${SOURCE_FILES} ${SOURCES_FILES_TEST} test/main_gtest.cpp)
