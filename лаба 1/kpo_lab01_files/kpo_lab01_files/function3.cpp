#include "stdafx.h"
// Функция для вычисления дней до ближайшего дня рождения
int daysUntilBirthday(int currentDay, int currentMonth, int currentYear, int birthDay, int birthMonth, bool yearisleap) {
   
    int currentDayOfYear = dayOfYear(currentDay, currentMonth, currentYear, yearisleap);
    int birthdayDayOfYear = dayOfYear(birthDay, birthMonth, currentYear, yearisleap);

    if (birthdayDayOfYear <= currentDayOfYear) {
        birthdayDayOfYear += 365; // Если день рождения уже прошел в текущем году, добавляем 365 дней
    }
    if (birthdayDayOfYear <= currentDayOfYear && yearisleap ) {
        birthdayDayOfYear += 366; 
    }

    return birthdayDayOfYear - currentDayOfYear;
}
