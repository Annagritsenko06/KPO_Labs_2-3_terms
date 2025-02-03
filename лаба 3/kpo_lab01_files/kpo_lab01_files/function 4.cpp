#include <iostream>
#include <string>
#include "stdafx.h"
using namespace std;

void holiday(int ordinalDay, int& day, int& month) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // ÷икл дл€ определени€ мес€ца 
    int i;
    for (i =0; i < 12; i++) {
        if (ordinalDay <= daysInMonth[i]) {
            break;
        }
        ordinalDay -= daysInMonth[i];
    }

    day = ordinalDay;
    month = i+1;
}


