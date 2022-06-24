cmake_minimum_required(VERSION 3.13)
set(PROJECT_ID image_processor__skeleton)

project(${PROJECT_ID})

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-lstdc++fs -Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion)

if (WIN32)
    add_compile_options(-Wno-multichar)
endif (WIN32)

include_directories(include)

set(SOURCE_FILES
        src/bitmap.c
        src/improc.cpp
        src/imqueue.cpp)

set(SOURCES_FILES_TEST
        test/test_aux.cpp
        test/test_improc.cpp
        test/test_imqueue.cpp
        test/test_io.cpp
        )

#set(GTEST_ROOT
# D:/ProgramData/CLion/agh/mdig-agh-lang_cpp__exercises__en-b8fe6a7ea81f/googletest-master)



add_executable(image_processor__debug ${SOURCE_FILES} main.cpp)

#add_executable(image_processor__test ${SOURCE_FILES} ${SOURCES_FILES_TEST} test/main_gtest.cpp)

if(EXISTS ${PROJECT_SOURCE_DIR}/test)
    set(EXEC_TEST ${PROJECT_ID}__test)
    add_executable(${EXEC_TEST} ${SOURCE_FILES} ${SOURCES_FILES_TEST} test/main_gtest.cpp)

    # == Uwzględnij pliki frameworku Google Testing Framework (GTF) ==

    # Przyjmij, że główny katalog z plikami frameworku GTF znajduje się
    # dwa katalogi wyżej względem katalogu projektu.
    set(GTEST_ROOT D:/ProgramData/CLion/agh/mdig-agh-lang_cpp__exercises__en-b8fe6a7ea81f/googletest-master)

    # Dodaj katalogi z plikami nagłówkowymi GTF.
    target_include_directories(${EXEC_TEST} PUBLIC
            ${GTEST_ROOT}/googlemock/include
            ${GTEST_ROOT}/googletest/include
            )

    add_subdirectory(${GTEST_ROOT} googletest-master)

    # Dołącz bibliotekę Google Mock.
    target_link_libraries(${EXEC_TEST} gmock)
endif()