cmake_minimum_required(VERSION 3.10)

project(CardRPGGame VERSION 1.0 LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем ccache (CI передаёт переменные окружения)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

# (Опционально) чтобы генерировался compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Собираем все .cpp (игнорируем старые main.cc и любые файлы в build/)
file(GLOB_RECURSE ALL_SRCS
    "${CMAKE_SOURCE_DIR}/*.cpp"
)
list(FILTER ALL_SRCS EXCLUDE REGEX ".*/main\\.cc$")
list(FILTER ALL_SRCS EXCLUDE REGEX ".*/build/.*")

# Создаём исполняемый файл
add_executable(game ${ALL_SRCS})
