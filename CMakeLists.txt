cmake_minimum_required(VERSION 3.10)

project(CardRPGGame VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Убедимся, что включаем заголовки из корня
include_directories(${CMAKE_SOURCE_DIR})

# Собираем рекурсивно все ваши .cpp/.cc из SRC_DIR (корня проекта),
# но потом исключаем из списка всё, что лежит в папке build/ 
# (и, на всякий случай, CMakeCXXCompilerId.cpp)
file(GLOB_RECURSE ALL_SOURCES
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.cc"
)

# Убираем из списка всё из build/ и сам CMakeCXXCompilerId.cpp
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*/build/.*")
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*/CMakeCXXCompilerId\\.cpp$")

add_executable(game ${ALL_SOURCES})

# (Опционально) если у вас есть внешние библиотеки — линковка тут:
# target_link_libraries(game PRIVATE ...)

