cmake_minimum_required(VERSION 3.17)
project(matrix_pr C)

set(CMAKE_C_STANDARD 99)

add_executable(matrix_pr main.c methods/menu.c headers/menu.h methods/matrix.c headers/matrix.h methods/functions.c headers/functions.h methods/math.c headers/math.h methods/complex.c headers/complex.h test.c test.h)