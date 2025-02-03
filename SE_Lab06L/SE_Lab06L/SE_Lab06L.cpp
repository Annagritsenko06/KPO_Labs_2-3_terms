#include "Dictionary.h"
#include <iostream>

using namespace std;
using namespace Dictionary;

Instance Dictionary::Create(const char* name, int size) {
    Instance temp;
    if (strlen(name) > DICTNAMEMAXSIZE) {
        throw THROW01;
    }
    else {
        strcpy_s(temp.name, name);
    }
    if (size > temp.maxsize) {
        throw THROW02;
    }
    else {
        temp.size = size;
    }
    temp.dictionary = new Entry[size];
    return temp;
}

void Dictionary::AddEntry(Instance& inst, Entry ed) {
    if (inst.count >= inst.size) {
        throw THROW03;
    }
    else {
        inst.dictionary[inst.count] = ed;
        for (int i = 0; i < inst.count; i++) {
            if (inst.dictionary[i].id == ed.id) {
                throw THROW04;
            }
        }
        inst.count++;
    }
}

void Dictionary::DelEntry(Instance& inst, int id) {
    for (int i = 0; i < inst.count; i++) {
        if (inst.dictionary[i].id == id) {
            for (int j = i; j < inst.count; j++) {
                inst.dictionary[j] = inst.dictionary[j + 1];
            }
            inst.count--;
            return;
        }
    }
    throw THROW06;
}

Entry Dictionary::GetEntry(Instance inst, int id) {
    for (int i = 0; i < inst.count; i++) {
        if (inst.dictionary[i].id == id) {
            return inst.dictionary[i];
        }
    }
    throw THROW05;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) {
    for (int i = 0; i < inst.count; i++) {
        if (inst.dictionary[i].id == id) {
            for (int j = 0; j < inst.count; j++) {
                if (new_ed.id == inst.dictionary[j].id) {
                    throw THROW08;
                }
            }
            inst.dictionary[i].id = new_ed.id;
            strcpy_s(inst.dictionary[i].name, new_ed.name);
            return;
        }
    }
    throw THROW07;
}

void Dictionary::Delete(Instance& inst) {
    delete[] inst.dictionary;
}

void Dictionary::Print(Instance inst) {
    if (inst.count == 0) {
        throw THROW09;
    }
    cout << "--------- " << inst.name << " -----------\n";
    for (int i = 0; i < inst.count; i++) {
        cout << inst.dictionary[i].id << ' ' << inst.dictionary[i].name << '\n';
    }
}