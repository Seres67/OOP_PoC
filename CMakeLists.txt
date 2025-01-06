project(poo)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fms-extensions")

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

include_directories(include)

add_executable(poo src/main.c src/entity.c src/character.c)
