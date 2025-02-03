#include <iostream>
#include <locale>
#include "C:\Users\admin\Documents\уник\кпо\SE_Lab06L\SE_Lab06L\Dictionary.h"
#pragma comment (lib,"C:\\Users\\admin\\Documents\\уник\\кпо\\лаба_6\\SE_Lab06S\\x64\\Debug\\SE_Lab06L.lib")

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        Dictionary::Instance d1 = Dictionary::Create("xxx", 10);
        Dictionary::Entry e1 = { 1,"abcd" }, e2 = { 2,"efg" };
        Dictionary::AddEntry(d1, e1);
        Dictionary::AddEntry(d1, e2);
        Dictionary::Print(d1); 
    }
    catch (const char* e) 
    {
        cout << "Ошибка: " << e << endl;
    };

    system("pause");
    return 0;
}