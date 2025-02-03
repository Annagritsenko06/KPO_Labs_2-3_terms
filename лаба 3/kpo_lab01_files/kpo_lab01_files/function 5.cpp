#include <iostream>
#include <cmath> 
#include "stdafx.h"

const char* getMonthName(int month) {
    const char* monthNames[] = {
        "Январь", "Февраль", "Март", "Апрель",
        "Май", "Июнь", "Июль", "Август",
        "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    if (month >= 1 && month <= 12) {
        return monthNames[month - 1];
    }
    else {
        return "Неверный номер месяца";
    }
}


   