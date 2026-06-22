cmake_minimum_required(VERSION 3.16)

project(yousyas_game LANGUAGES CXX)

add_executable(yousyas_game main.cpp)
target_compile_features(yousyas_game PRIVATE cxx_std_17)

if(MSVC)
  target_compile_options(yousyas_game PRIVATE /utf-8)
else()
  target_compile_options(yousyas_game PRIVATE
    -finput-charset=UTF-8
    -fexec-charset=UTF-8
  )
endif()
