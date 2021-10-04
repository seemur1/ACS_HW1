#ifndef ACS_HW1_CONTAINER_H
#define ACS_HW1_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "number.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива указателей.
typedef struct {
    int len; // текущая длина
    number **cont;
} container;

// Инициализация контейнера
void Init(container *c, int *size);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container *c);

// Ввод содержимого контейнера из указанного потока
void In(container *c, FILE *fp, const int *size);

// Случайный ввод содержимого контейнера
void InRnd(container *c, int size);

// Вывод содержимого контейнера в указанный файл
void Out(container const *c, FILE *fp);

// Поиск позиции для вставки (через бин поиск)
int BinarySearch(container const *c, number *item, int l_border, int r_border);

// Сортировка бинарными вставками
void BinaryInsertion(container *c);

#endif //ACS_HW1_CONTAINER_H
