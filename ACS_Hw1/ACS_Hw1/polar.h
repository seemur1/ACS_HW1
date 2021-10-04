#ifndef ACS_HW1_POLAR_H
#define ACS_HW1_POLAR_H

//------------------------------------------------------------------------------
// polar.h - содержит описание полярного числа и его интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include <stdbool.h>
#include <stdio.h>

// Полярное число
typedef struct {
    double angle, radius; //Угол, радиус
} polar;

// Подсчёт значения полярного числа.
double p_cast (polar * const me);

// Вывод параметров полярного числа в файл
bool p_Out (polar * const me, FILE *fp);

// Ввод параметров полярного числа из файла
int p_In(polar *p, FILE *fp);

// Ввод случайных параметров полярного числа
bool p_InRnd(polar *p);

#endif //ACS_HW1_POLAR_H
