#include <iostream>
#include <cmath> 
using namespace std;
// Функция для определения високосного года
bool leapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для вычисления порядкового номера дня в году
int dayOfYear(int day, int month, int year) {
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int result = day;

    for (int i = 1; i < month; ++i) {
        result += daysInMonth[i];
    }

    if (month > 2 && leapYear(year)) {
        result += 1;
    }

    return result;
}

// Функция для вычисления дней до ближайшего дня рождения
int daysUntilBirthday(int currentDay, int currentMonth, int currentYear, int birthDay, int birthMonth) {
    
    int currentDayOfYear = dayOfYear(currentDay, currentMonth, currentYear);
    int birthdayDayOfYear = dayOfYear(birthDay, birthMonth, currentYear);

    if (birthdayDayOfYear <= currentDayOfYear) {
        birthdayDayOfYear += 365; // Если день рождения уже прошел в текущем году, добавляем 365 дней
    }

    return birthdayDayOfYear - currentDayOfYear;
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    int day, month, year;
    for (;;) {
        cout << "Введите дату в формате ДДММГГГГ: ";
        cin >> day >> month >> year;
        if (day < 0) {
            cout << "Error!Введите корректную дату!" << endl;
            continue;
            cout << endl;
        }
        if (day > 31) {
            cout << "Error!Введите корректную дату!" << endl;
            continue;
            cout << endl;
            if (day != static_cast<int>(day)) {
                cout << "Error!Введите корректную дату!" << endl;
                continue;
                cout << endl;
            }
            if (month < 0) {
                cout << "Error!Введите корректную дату!" << endl;
                continue;
                cout << endl;
            }
            if (month != static_cast<int>(month)) {
                cout << "Error!Введите корректную дату!" << endl;
                continue;
                cout << endl;
            }
            if (month > 12) {
                cout << "Error!Введите правильно месяц!" << endl;
                continue;
                cout << endl;
            }
            if (year < 0) {
                cout << "Error!Введите корректную дату!" << endl;
                continue;
                cout << endl;
            }
            if (year != static_cast<int>(year)) {
                cout << "Error!Введите корректную дату!" << endl;
                continue;
                cout << endl;
            }
            // Проверка на високосный год
            if (leapYear(year)) {
                cout << year << " год является високосным." << endl;
            }
            else {
                cout << year << " год не является високосным." << endl;
            }
        }
        // Вычисление порядкового номера дня в году
        int dayNumber = dayOfYear(day, month, year);
        cout << "Порядковый номер дня в году: " << dayNumber << endl;

        // Вычисление дней до ближайшего дня рождения 
        int birthDay;
        int birthMonth;
        cout << "Введите дату рождения: " << endl;
        cin >> birthDay >> birthMonth;
        int daysUntilBD = daysUntilBirthday(day, month, year, birthDay, birthMonth);
        cout << "Кол-во дней до ближайшего дня рождения: " << daysUntilBD << endl;

        return 0;
    }
}
