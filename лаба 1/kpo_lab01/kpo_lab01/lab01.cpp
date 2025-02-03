#include <iostream>
#include <cmath> 
using namespace std;
// ������� ��� ����������� ����������� ����
bool leapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ������� ��� ���������� ����������� ������ ��� � ����
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

// ������� ��� ���������� ���� �� ���������� ��� ��������
int daysUntilBirthday(int currentDay, int currentMonth, int currentYear, int birthDay, int birthMonth) {
    
    int currentDayOfYear = dayOfYear(currentDay, currentMonth, currentYear);
    int birthdayDayOfYear = dayOfYear(birthDay, birthMonth, currentYear);

    if (birthdayDayOfYear <= currentDayOfYear) {
        birthdayDayOfYear += 365; // ���� ���� �������� ��� ������ � ������� ����, ��������� 365 ����
    }

    return birthdayDayOfYear - currentDayOfYear;
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    int day, month, year;
    for (;;) {
        cout << "������� ���� � ������� ��������: ";
        cin >> day >> month >> year;
        if (day < 0) {
            cout << "Error!������� ���������� ����!" << endl;
            continue;
            cout << endl;
        }
        if (day > 31) {
            cout << "Error!������� ���������� ����!" << endl;
            continue;
            cout << endl;
            if (day != static_cast<int>(day)) {
                cout << "Error!������� ���������� ����!" << endl;
                continue;
                cout << endl;
            }
            if (month < 0) {
                cout << "Error!������� ���������� ����!" << endl;
                continue;
                cout << endl;
            }
            if (month != static_cast<int>(month)) {
                cout << "Error!������� ���������� ����!" << endl;
                continue;
                cout << endl;
            }
            if (month > 12) {
                cout << "Error!������� ��������� �����!" << endl;
                continue;
                cout << endl;
            }
            if (year < 0) {
                cout << "Error!������� ���������� ����!" << endl;
                continue;
                cout << endl;
            }
            if (year != static_cast<int>(year)) {
                cout << "Error!������� ���������� ����!" << endl;
                continue;
                cout << endl;
            }
            // �������� �� ���������� ���
            if (leapYear(year)) {
                cout << year << " ��� �������� ����������." << endl;
            }
            else {
                cout << year << " ��� �� �������� ����������." << endl;
            }
        }
        // ���������� ����������� ������ ��� � ����
        int dayNumber = dayOfYear(day, month, year);
        cout << "���������� ����� ��� � ����: " << dayNumber << endl;

        // ���������� ���� �� ���������� ��� �������� 
        int birthDay;
        int birthMonth;
        cout << "������� ���� ��������: " << endl;
        cin >> birthDay >> birthMonth;
        int daysUntilBD = daysUntilBirthday(day, month, year, birthDay, birthMonth);
        cout << "���-�� ���� �� ���������� ��� ��������: " << daysUntilBD << endl;

        return 0;
    }
}
