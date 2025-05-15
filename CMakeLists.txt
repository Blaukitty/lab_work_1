cmake_minimum_required(VERSION 3.10)

project(CardRPGGame VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Если у вас есть папка include/ — добавьте её:
# include_directories(${CMAKE_SOURCE_DIR}/include)

# 1) Собираем все .cpp и .cc в корне
file(GLOB_RECURSE ALL_SRCS
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.cc"
)

# 2) Исключаем из build/ (чтобы не тащить CMakeCXXCompilerId.cpp)
list(FILTER ALL_SRCS EXCLUDE REGEX ".*/build/.*")
# 3) Ещё раз на всякий случай исключаем сам CompilerId-файл
list(FILTER ALL_SRCS EXCLUDE REGEX ".*/CMakeCXXCompilerId\\.cpp$")

# 4) (Опционально) исключаем старые источники, если они мешают
# list(FILTER ALL_SRCS EXCLUDE REGEX ".*/main\\.cc$")

# 5) Делаем исполняемый файл
add_executable(game ${ALL_SRCS})

# --- Готово! ---



