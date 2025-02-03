#pragma once
const char* getMonthName(int month);
void holiday(int ordinalDay, int& day, int& month);
bool leapYear(int year);
int dayOfYear(int day, int month, int year, bool yearisleap);
int daysUntilBirthday(int currentDay, int currentMonth, int currentYear, int birthDay, int birthMonth, bool yearisleap);