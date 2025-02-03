#include "stdafx.h"
// ������� ��� ���������� ���� �� ���������� ��� ��������
int daysUntilBirthday(int currentDay, int currentMonth, int currentYear, int birthDay, int birthMonth, bool yearisleap) {
   
    int currentDayOfYear = dayOfYear(currentDay, currentMonth, currentYear, yearisleap);
    int birthdayDayOfYear = dayOfYear(birthDay, birthMonth, currentYear, yearisleap);

    if (birthdayDayOfYear <= currentDayOfYear) {
        birthdayDayOfYear += 365; // ���� ���� �������� ��� ������ � ������� ����, ��������� 365 ����
    }
    if (birthdayDayOfYear <= currentDayOfYear && yearisleap ) {
        birthdayDayOfYear += 366; 
    }

    return birthdayDayOfYear - currentDayOfYear;
}
