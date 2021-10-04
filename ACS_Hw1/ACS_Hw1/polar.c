//------------------------------------------------------------------------------
// polar.c - содержит процедуру ввода параметров
// для уже созданного полярного числа.
//------------------------------------------------------------------------------
#include "polar.h"
#include "string.h"

//------------------------------------------------------------------------------
// Вычисление значения комплексного числа.
double p_cast (polar * const me) {
    return me->radius;
}

//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в файл
bool p_Out(polar * const me, FILE *fp) {
    fprintf(fp, "It is Polar Coords: radius = %f"
                ", angle = %f\n", me->radius, me->angle);
    return true;
}

//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из файла
int p_In(polar *p, FILE *fp) {
    char buffer1[100], buffer2[100];
    if (fscanf(fp, "%s%s", buffer1, buffer2) == EOF) { return 2; }
    if ((((p->radius = atof(buffer1)) == 0) && (strcmp(buffer1, "0") != 0)) ||
        (((p->angle = atof(buffer2)) == 0) && (strcmp(buffer2, "0") != 0))) { return 0; }
    return 1;
}

// Случайный ввод параметров комплексного числа
bool p_InRnd(polar *p) {
    p->radius = Random();
    p->angle = Random();
    return true;
}