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
        cout << "������� ���� � ������� ��������: ";
        cin >> day >> month >> year;
        cout << "������� ���� ��������: " << endl;
        cin >> birthDay >> birthMonth;
        
        const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month < 1 ||  month > 12 || day < 1 || day > daysInMonth[month]||(day == 29 && month == 2 && !leapYear(year))) {
            cout << "������������ ����." << endl;
            return -1;
        }
            // �������� �� ���������� ���
            if (leapYear(year)) {
                yearisleap=true;
                cout << year << " ��� �������� ����������." << endl;
            }
            else {
                yearisleap = false;
                cout << year << " ��� �� �������� ����������." << endl;
            }
        
        // ���������� ����������� ������ ��� � ����
        int dayNumber = dayOfYear(day, month, year,yearisleap); 
        cout << "���������� ����� ��� � ����: " << dayNumber << endl;

        // ���������� ���� �� ���������� ��� �������� 
        int daysUntilBD = daysUntilBirthday(day, month, year, birthDay, birthMonth, yearisleap); 
        cout << "���-�� ���� �� ���������� ��� ��������: " << daysUntilBD << endl;

        return 0;
    }
}