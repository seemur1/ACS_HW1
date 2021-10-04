#ifndef ACS_HW1_COMPLEX_NUMBER_H
#define ACS_HW1_COMPLEX_NUMBER_H

//------------------------------------------------------------------------------
// complex_number.h - содержит описание комплексного числа и его интерфейса
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdio.h>
#include "rnd.h"

// Комплексное число.
typedef struct {
    double real, imaginary; // Мнимая, действительные части.
} complex_number;

// Вычисление "длины" комплексного числа.
double c_cast (complex_number * const me);

// Вывод параметров комплексного числа в файл
bool c_Out (complex_number * const me, FILE *fp);

// Ввод параметров комплексного числа из файла
int c_In(complex_number *c, FILE *fp);

// Случайный ввод параметров комплексного числа.
bool c_InRnd(complex_number *c);

#endif //ACS_HW1_COMPLEX_NUMBER_H
