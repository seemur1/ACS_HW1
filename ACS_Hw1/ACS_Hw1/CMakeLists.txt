cmake_minimum_required(VERSION 3.20)
project(ACS_Hw1 C)

set(CMAKE_C_STANDARD 90)

add_executable(ACS_Hw1 main.c number.c number.h fraction.c fraction.h polar.c polar.h complex_number.c complex_number.h container.c container.h rnd.h rnd.c)
