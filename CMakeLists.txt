# CMakeList.txt: проект CMake для Program_parallelization; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.15)

project ("Home_Library")

add_executable(Home_Library    
    main.cpp
    HomeLibrary.cpp
 )
  
set_property(TARGET Home_Library PROPERTY CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Home_Library PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Home_Library PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(Home_Library PUBLIC cxx_std_20)