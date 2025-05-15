cmake_minimum_required(VERSION 3.10)

project(CardRPGGame LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем заголовки из корня (если нужно)
include_directories(${CMAKE_SOURCE_DIR})

# Собираем все .cpp в корне проекта
file(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

# Опционально исключаем старый main.cc, если он мешает
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*/main\\.cc$")

# Создаём исполняемый файл
add_executable(game ${SOURCE_FILES})


