#pragma once
#include <cstring>
#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной ёмкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"
#define THROW09 "Print: словарь пуст"

namespace Dictionary {
    struct Entry {
        int id;
        char name[ENTRYNAMEMAXSIZE];
    };

    struct Instance {
        char name[ENTRYNAMEMAXSIZE];
        int maxsize = DICTMAXSIZE;
        int size = 0;
        int count = 0;
        Entry* dictionary;
    };

    Instance Create(const char* name, int size);
    void AddEntry(Instance& inst, Entry ed);
    void DelEntry(Instance& inst, int id);
    void UpdEntry(Instance& inst, int id, Entry new_ed);
    Entry GetEntry(Instance inst, int id);
    void Print(Instance d);
    void Delete(Instance& d);
}