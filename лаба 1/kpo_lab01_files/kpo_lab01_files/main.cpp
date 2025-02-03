#include <iostream>
#include <cmath> 
#include "stdafx.h"
using namespace std;

int main() {
    setlocale(LC_CTYPE, "RUS");
    int day, month, year;
    int birthDay;
    int birthMonth;
    bool yearisleap;
    for (;;) {
        cout << "Введите дату в формате ДДММГГГГ: ";
        cin >> day >> month >> year;
        cout << "Введите дату рождения: " << endl;
        cin >> birthDay >> birthMonth;
        
        const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month < 1 ||  month > 12 || day < 1 || day > daysInMonth[month]||(day == 29 && month == 2 && !leapYear(year))) {
            cout << "Некорректная дата." << endl;
            return -1;
        }
            // Проверка на високосный год
            if (leapYear(year)) {
                yearisleap=true;
                cout << year << " год является високосным." << endl;
            }
            else {
                yearisleap = false;
                cout << year << " год не является високосным." << endl;
            }
        
        // Вычисление порядкового номера дня в году
        int dayNumber = dayOfYear(day, month, year,yearisleap); 
        cout << "Порядковый номер дня в году: " << dayNumber << endl;

        // Вычисление дней до ближайшего дня рождения 
        int daysUntilBD = daysUntilBirthday(day, month, year, birthDay, birthMonth, yearisleap); 
        cout << "Кол-во дней до ближайшего дня рождения: " << daysUntilBD << endl;

        return 0;
    }
}