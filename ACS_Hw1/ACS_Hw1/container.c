//------------------------------------------------------------------------------
// container.c - содержит функции обработки контейнера
//------------------------------------------------------------------------------
#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container *c, int *size) {
    printf("Start Init\n");
    c->cont = malloc(*size * sizeof(number*));
    c->len = 0;
    printf("End Init\n");
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container *c) {
    for (int i = 0; i < c->len; ++i) {
        switch(c->cont[i]->k) {
            case COMPLEX:
                free(c->cont[i]->complex_n);
                break;
            case POLAR:
                free(c->cont[i]->pol);
                break;
            case FRACTION:
                free(c->cont[i]->fract);
                break;
        }
    }
    free(*(c->cont));
    free(c->cont);
    c->len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного файла
void In(container *c, FILE *fp, const int* size) {
    int result;
    while(c->len < *size) {
        c->cont[c->len] = malloc(sizeof(number));
        result = n_In(c->cont[c->len], fp);
        if (result == 1) { c->len++; }
        else if (result == 2) { return; }
        else { free(c->cont[c->len]); }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container *c, int size) {
    printf("Start Rnd\n");
    while(c->len < size) {
        c->cont[c->len] = malloc(sizeof(number));
        n_InRnd(c->cont[c->len++]);
    }
    printf("End Rnd\n");
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container const *c, FILE *fp) {
    fprintf(fp, "Container contains %d elements.\n", c->len);
    for(int i = 0; i < c->len; i++) {
        fprintf(fp, "%d: ", i);
        n_Out(c->cont[i], fp);
    }
}

//------------------------------------------------------------------------------
// Поиск позиции для вставки (через бин поиск)
int BinarySearch(container const *c, number *const item, int l_border, int r_border) {
    if (r_border <= l_border) { return (n_cast(item) > n_cast(c->cont[l_border])) ? (l_border + 1) : l_border; }

    int mid = (l_border + r_border) / 2;

    if (n_cast(item) == n_cast(c->cont[mid])) { return mid + 1; }

    if (n_cast(item) > n_cast(c->cont[l_border])) { return BinarySearch(c, item, mid + 1, r_border); }
    return BinarySearch(c, item, l_border, mid - 1);
}

//------------------------------------------------------------------------------
// Сортировка бинарными вставками
void BinaryInsertion(container *c) {
    int loc, counter;
    number *selected;

    for (int j = 0; j < c->len - 1; ++j)
    {
        counter = j;
        selected = malloc(sizeof(number));
        selected->k = c->cont[counter + 1]->k;
        if (selected->k == FRACTION) { selected->fract = c->cont[counter + 1]->fract; }
        else if (selected->k == COMPLEX) { selected->complex_n = c->cont[counter + 1]->complex_n; }
        else { selected->pol = c->cont[counter + 1]->pol; }
        // find location where selected should be inserted
        loc = BinarySearch(c, selected, 0, counter);
        free(c->cont[counter + 1]);
        // Move all elements after location to create space
        while (counter >= loc) {
            c->cont[counter + 1] = c->cont[counter];
            counter--;
        }
        c->cont[counter + 1] = selected;
    }
}
