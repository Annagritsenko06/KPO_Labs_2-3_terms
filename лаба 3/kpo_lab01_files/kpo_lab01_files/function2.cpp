#include "stdafx.h"
#include <iostream>
#include <cmath> 

// Функция для вычисления порядкового номера дня в году
int dayOfYear(int day, int month, int year, bool yearisleap) {
    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int result = day;
    for (int i = 0; i < month-1; ++i) {
        result += daysInMonth[i];
    }

    if (month > 2 && yearisleap) {
        result += 1;
    }

    return result;
}