cmake_minimum_required(VERSION 3.15)
project(game)

set(CMAKE_CXX_STANDARD 17)

option(ENABLE_ASAN   "Enable AddressSanitizer memory checks" OFF)

if(ENABLE_ASAN)
  message(STATUS "AddressSanitizer ENABLED")
  # компилятор
  add_compile_options(
    -O1                   # ASan рекомендует O1
    -g                    # отладочные символы
    -fsanitize=address    # включаем ASan
    -fno-omit-frame-pointer
  )
  # линкер
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif()

add_executable(game game2.cpp)
