#ifndef ACS_HW1_FRACTION_H
#define ACS_HW1_FRACTION_H

//------------------------------------------------------------------------------
// fraction.h - содержит описание дроби и её интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include <stdbool.h>
#include <stdio.h>

// Дробь
typedef struct {
    int numerator, denominator; //делимое, делитель
} fraction;

// Подсчёт значения дроби
double f_cast (fraction * const me);

// Вывод параметров дроби в файл
bool f_Out (fraction * const me, FILE *fp);

// Ввод параметров дроби из файла
int f_In(fraction *f, FILE *fp);

// Ввод случайных параметров дроби
bool f_InRnd(fraction *f);

#endif //ACS_HW1_FRACTION_H
