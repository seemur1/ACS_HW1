//------------------------------------------------------------------------------
// complex_number.c - содержит процедуру ввода параметров
// для уже созданного комплексного числа
//------------------------------------------------------------------------------
#include "complex_number.h"
#include <math.h>
#include "string.h"

//------------------------------------------------------------------------------
// Вычисление значения комплексного числа
double c_cast (complex_number * const me) {
    return sqrt(me->real * me->real + me->imaginary * me->imaginary);
}

//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в файл
bool c_Out(complex_number * const me, FILE *fp) {
    fprintf(fp, "It is Complex Number: real value = %f"
                ", imaginary value = %f\n", me->real, me->imaginary);
    return true;
}

//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из файла
int c_In(complex_number *c, FILE *fp) {
    char buffer1[100], buffer2[100];
    if (fscanf(fp, "%s%s", buffer1, buffer2) == EOF) { return 2; }
    if ((((c->real = atof(buffer1)) == 0) && (strcmp(buffer1, "0") != 0)) ||
        (((c->imaginary = atof(buffer2)) == 0) && (strcmp(buffer2, "0") != 0))) { return 0; }
    return 1;
}
// Случайный ввод параметров комплексного числа
bool c_InRnd(complex_number *c) {
    c->real = Random();
    c->imaginary = Random();
    return true;
}
