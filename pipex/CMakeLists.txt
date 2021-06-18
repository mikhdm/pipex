cmake_minimum_required(VERSION 3.5)
project(pipex)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SOURCE_DIR cmake.debug)

include_directories(include)

add_executable(pipex
./src/utils/ft_strlen_until.c
./src/utils/ft_strdup_until.c
./src/utils/ft_split.c
./src/pipex.c
./src/error.c
./src/parse.c)
