#include <iostream>
#include <cmath> 
#include "stdafx.h"
// Функция для определения високосного года
bool leapYear(int year) {
    return year % 4 == 0 && year % 100 != 0;
}
       