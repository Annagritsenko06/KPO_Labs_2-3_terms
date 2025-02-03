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
        cout << "������� ���� � ������� ��������: ";
        cin >> date;

        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(2, 2));
         year = stoi(date.substr(4, 4));
       
         const int daysInMonth[] = {  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
         if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month-1]||(day == 29 && month == 2 && !leapYear(year))) {
             cout << "������������ ����." << endl;
             continue;
         }
        // ���������� ������� ��� ��������� �������� ������
        const char* monthName = getMonthName(month);
        cout << "�������� ������: " << monthName << endl; 
        cout << "������� ���� ��������: " << endl;
        cin >> birthdate;

        birthDay = stoi(birthdate.substr(0, 2));
        birthMonth = stoi(birthdate.substr(2, 2));
        if (birthMonth < 1 || birthMonth > 12 || birthDay < 1 || birthDay > daysInMonth[month-1] || (birthDay >29 && birthMonth == 2 )) {

            cout << "������������ ����!" << '\n';
            continue;

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

      
        int eventDay, eventMonth, ordinalDay;
        cout << "������� ���������� ����� ��� � ����: ";
        cin >> ordinalDay;
        holiday(ordinalDay, eventDay, eventMonth);

        cout << "������� � ���������� ������� " << ordinalDay << " ���������� �� " << eventDay << "." << eventMonth << endl;

        // ������� ���������� �������
        if (ordinalDay == (leapYear(year) ? 257 : 256)) {
            cout << "���� ������������!" << endl;
        }

        if (ordinalDay ==(leapYear(year) ? 153 : 152)) {
            cout << "������ ���� ����!" << endl;
        }

        if (ordinalDay == (leapYear(year) ? 245 : 244)) {
            cout << "������ ���� �����!" << endl;
        }

        if (ordinalDay == (leapYear(year) ? 336 : 335)) {
            cout << "������ ���� ����!" << endl;
        }

        if (ordinalDay == (leapYear(year) ? 61 : 60)) {
            cout << "������ ���� �����!" << endl;
        }

        return 0;

    }
}