#ifndef ACS_HW1_NUMBER_H
#define ACS_HW1_NUMBER_H

//------------------------------------------------------------------------------
// number.h - содержит описание обобщённого числа и его интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include <stdbool.h>
#include <stdio.h>
#include "fraction.h"
#include "complex_number.h"
#include "polar.h"

// Пространство имён "наследников"
enum key {FRACTION, COMPLEX, POLAR};

// Обобщённое число.
typedef struct {
    enum key k; // Тип числа
    // Настоящее значение "под ним"
    union{
        fraction *fract;
        complex_number *complex_n;
        polar *pol;
    };
} number;

// Подсчёт значения обобщённого числа.
double n_cast(number * const me);

// Вывод параметров обобщённого числа в файл
bool n_Out (number * const me, FILE *fp);

// Ввод параметров обобщённого числа из файла
int n_In(number *n, FILE *fp);

// Ввод случайных обобщённого полярного числа
bool n_InRnd(number *n);

#endif //ACS_HW1_NUMBER_H
