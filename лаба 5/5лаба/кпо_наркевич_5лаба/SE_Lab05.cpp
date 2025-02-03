#include "stdafx.h"
#include "Dictionary.h"

using namespace Dictionary;
int main() {

#if defined(TEST_CREATE_01)
    Instance d1 = Create("Препли", 6);
#elif defined(TEST_CREATE_02)
    Instance d2 = Create("Студенты", 900);
#else
    Instance d1 = Create("Преподаватели", 9);
#endif
#if defined(TEST_ADDENTRY_04)
    Entry a5 = { 1, "Прилучный" };
#else
    Entry a5 = { 4, "Прилучный" };
#endif
#if defined(TEST_ADDENTRY_03)
    AddEntry(d, a10);
#endif
#if defined(TEST_GETENTRY_05)
    GetEntry(d1, 1000);
#else
    GetEntry(d1, 7);
#endif
#if defined(TEST_GETENTRY_06)
    DelEntry(d, 1000);
#else
    DelEntry(d1, 4);
#endif
    
#if defined(TEST_PRINT_09)
    Print(s);
#endif

    setlocale(LC_ALL, "RU");
    Entry a1 = { 1, "Лопаревич" };
    Entry a2 = { 2, "Ларченко" };
    Entry a3 = { 3, "Гриц" };
    Entry a4 = { 6, "Кравченко" };
    Entry a6 = { 5, "Бабарыкин" };
    Entry a7 = { 7, "Воловская" };
    Entry a8 = { 8, "Кудрявцева" };
    Entry a9 = { 9, "Курс" };
    Entry a10 = { 10, "Вашкевич" };
    Entry a11 = { 4, "Семенович" };
#if defined(TEST_UPDENTRY_07)
    UpdEntry(d1, 1000, a10);
#elif defined(TEST_UPDENTRY_08);
    UpdEntry(d1, 7, a11);
#else
    UpdEntry(d1, 7, a10);
#endif
    AddEntry(d1, a1);
    AddEntry(d1, a2);
    AddEntry(d1, a3);
    AddEntry(d1, a4);
    AddEntry(d1, a5);
    AddEntry(d1, a6);
    AddEntry(d1, a7);
    AddEntry(d1, a8);
    AddEntry(d1, a9);
    Entry b1 = { 1, "Климанова" };
    Entry b2 = { 2, "Быков" };
    Entry b3 = { 3, "Ясенко" };
    Entry b4 = { 4, "Забаровская" };
    Entry b5 = { 5, "Дмитриенко" };
    Entry b6 = { 6, "Усович" };
    Entry b7 = { 7, "Грипко" };
    Instance d2 = Create("Студенты", 7);
    AddEntry(d2, b1);
    AddEntry(d2, b2);
    AddEntry(d2, b3);
    AddEntry(d2, b4);
    AddEntry(d2, b5);
    AddEntry(d2, b6);
    AddEntry(d2, b7);
    Print(d1);
    Print(d2);
    Delete(d1);
    Delete(d2);
}