cmake_minimum_required(VERSION 3.15)
project(game)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Собираем все .cpp и .cc в корне проекта
file(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
)

# Убираем main.cc, если вы используете только main.cpp
list(FILTER SOURCE_FILES EXCLUDE REGEX "main\\.cc$")

# Создаём исполняемый файл
add_executable(game ${SOURCE_FILES})

# (Опционально) ещё можно включить папку с заголовками, если они в поддиректориях
# target_include_directories(game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
