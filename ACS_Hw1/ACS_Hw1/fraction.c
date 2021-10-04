//------------------------------------------------------------------------------
// fraction.c - содержит процедуру ввода параметров
// для уже созданной дроби
//------------------------------------------------------------------------------
#include "fraction.h"
#include "string.h"
#include "stdlib.h"

//------------------------------------------------------------------------------
// Вычисление значения дроби
double f_cast (fraction * const me) {
    return (double)me->numerator / (double)me->denominator;
}

//------------------------------------------------------------------------------
// Вывод параметров дроби в файл
bool f_Out(fraction * const me, FILE *fp) {
    fprintf(fp, "It is Fraction: numerator = %d"
                ", denominator = %d\n", me->numerator, me->denominator);
    return true;
}

//------------------------------------------------------------------------------
// Ввод параметров дроби из файла
int f_In(fraction *f, FILE *fp) {
    char buffer1[100], buffer2[100], buffer3[100], buffer4[100];
    if (fscanf(fp, "%s%s", buffer1, buffer2) == EOF) { return 2; }
    strcpy(buffer1, buffer3);
    strcpy(buffer2, buffer4);
    sprintf(buffer1, "%d", f->numerator = atoi(buffer1));
    sprintf(buffer2, "%d", f->denominator = atoi(buffer2));
    if ((strlen(buffer1) != strlen(buffer3)) ||
        (strlen(buffer2) != strlen(buffer4)) ) {
        return 0;
    }
    return 1;
}

// Случайный ввод параметров дроби
bool f_InRnd(fraction *f) {
    f->numerator = Random();
    f->denominator = Random();
    return true;
}
