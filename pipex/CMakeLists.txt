cmake_minimum_required(VERSION 3.5)
project(pipex)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SOURCE_DIR cmake.debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

include_directories(include)

set(SRCS
./src/utils/ft_strlen_until.c 
./src/utils/ft_strlen.c 
./src/utils/ft_strdup_until.c 
./src/utils/ft_splitf.c 
./src/utils/ft_putendl_fd.c 
./src/utils/ft_putstr_fd.c 
./src/utils/ft_memcpy.c
./src/utils/ft_memset.c
./src/utils/ft_strjoin.c 
./src/utils/ft_strcmp.c 
./src/utils/ft_strchr.c 
./src/utils/alloca_to.c
./src/utils/cleanup.c
./src/utils/getbin.c
./src/utils/child_by_index.c
./src/utils/ft_isspace.c
./src/utils/ft_split.c
./src/utils/ft_lstadd_back.c 
./src/utils/ft_lstadd_front.c 
./src/utils/ft_lstclear.c 
./src/utils/ft_lstdelone.c 
./src/utils/ft_lstiter.c 
./src/utils/ft_lstlast.c 
./src/utils/ft_lstmap.c 
./src/utils/ft_lstnew.c 
./src/utils/ft_lstsize.c
./src/environ.c
./src/pipex.c
./src/error.c 
./src/main.c)

add_executable(pipex ${SRCS})
