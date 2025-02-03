#include <iostream>
#include <cmath> 
#include "stdafx.h"
#include <string>
using namespace std;
int main() {
    setlocale(LC_CTYPE, "RUS");
    int day, month, year;
    int birthDay;
    int birthMonth;
    bool yearisleap;
    string date;
    string birthdate;
    for (;;) { 
        cout << "Введите дату в формате ДДММГГГГ: ";
        cin >> date;

        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(2, 2));
         year = stoi(date.substr(4, 4));
       
         const int daysInMonth[] = {  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
         if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month-1]||(day == 29 && month == 2 && !leapYear(year))) {
             cout << "Некорректная дата." << endl;
             continue;
         }
        // Используем функцию для получения названия месяца
        const char* monthName = getMonthName(month);
        cout << "Название месяца: " << monthName << endl; 
        cout << "Введите дату рождения: " << endl;
        cin >> birthdate;

        birthDay = stoi(birthdate.substr(0, 2));
        birthMonth = stoi(birthdate.substr(2, 2));
        if (birthMonth < 1 || birthMonth > 12 || birthDay < 1 || birthDay > daysInMonth[month-1] || (birthDay >29 && birthMonth == 2 )) {

            cout << "Некорректный ввод!" << '\n';
            continue;

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

      
        int eventDay, eventMonth, ordinalDay;
        cout << "Введите порядковый номер дня в году: ";
        cin >> ordinalDay;
        holiday(ordinalDay, eventDay, eventMonth);

        cout << "Событие с порядковым номером " << ordinalDay << " приходится на " << eventDay << "." << eventMonth << endl;

        // Примеры конкретных событий
        if (ordinalDay == (leapYear(year) ? 257 : 256)) {
            cout << "День программиста!" << endl;
        }

        if (ordinalDay ==(leapYear(year) ? 153 : 152)) {
            cout << "Первый день лета!" << endl;
        }

        if (ordinalDay == (leapYear(year) ? 245 : 244)) {
            cout << "Первый день осени!" << endl;
        }

        if (ordinalDay == (leapYear(year) ? 336 : 335)) {
            cout << "Первый день зимы!" << endl;
        }

        if (ordinalDay == (leapYear(year) ? 61 : 60)) {
            cout << "Первый день весны!" << endl;
        }

        return 0;

    }
}