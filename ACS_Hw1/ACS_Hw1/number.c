//------------------------------------------------------------------------------
// number.c - содержит процедуру ввода параметров
// для уже созданного обобщённого числа.
//------------------------------------------------------------------------------
#include "number.h"

//------------------------------------------------------------------------------
// Вычисление значения обобщённого числа.
double n_cast(number * const me) {
    switch (me->k) {
        case FRACTION:
            return f_cast(me->fract);
        case COMPLEX:
            return c_cast(me->complex_n);
        case POLAR:
            return p_cast(me->pol);
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров обобщённого числа в файл
bool n_Out(number * const n, FILE *fp) {
    switch(n->k) {
        case COMPLEX:
            return c_Out(n->complex_n, fp);
        case POLAR:
            return p_Out(n->pol, fp);
        case FRACTION:
            return f_Out(n->fract, fp);
        default:
            fprintf(fp, "Incorrect figure!\n");
            return false;
    }
}

//------------------------------------------------------------------------------
// Ввод параметров обобщённого числа из файла
int n_In(number *n, FILE *fp) {
    int number_type;
    if (fscanf(fp, "%d", &number_type) == EOF) { return 2; }
    switch(number_type) {
        case 1:
            n->k = FRACTION;
            n->fract = malloc(sizeof(fraction));
            return f_In(n->fract, fp);
        case 2:
            n->k = POLAR;
            n->pol = malloc(sizeof(polar));
            return p_In(n->pol, fp);
        case 3:
            n->k = COMPLEX;
            n->complex_n = malloc(sizeof(complex_number));
            return c_In(n->complex_n, fp);
        default:
            return 0;
    }
}

// Случайный ввод параметров обобщённого числа
bool n_InRnd(number *n) {
    auto k = rand() % 3;
    switch(k) {
        case 0:
            n->k = FRACTION;
            n->fract = malloc(sizeof(fraction));
            return f_InRnd(n->fract);
        case 1:
            n->k = POLAR;
            n->pol = malloc(sizeof(polar));
            return p_InRnd(n->pol);
        default:
            n->k = COMPLEX;
            n->complex_n = malloc(sizeof(complex_number));
            return c_InRnd(n->complex_n);
    }
}
