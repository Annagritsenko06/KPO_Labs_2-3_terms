#include <iostream>
#include <string>
typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year; 
using namespace std;
struct Date {
    day dd;
    month mm;
    year УУУУ;
    
    // Перегрузка оператора <
    bool operator<(const Date& other) const {
        if (УУУУ != other.УУУУ)
            return УУУУ < other.УУУУ;
        if (mm != other.mm)
            return mm < other.mm;
        return dd < other.dd;
    }
    // Перегрузка оператора >
    bool operator>(const Date& other) const {
        return other < *this;
    }
    // Перегрузка оператора ==
    bool operator==(const Date& other) const {
        return УУУУ == other.УУУУ && mm == other.mm && dd == other.dd;
    }
};
struct Student{
    string name;
    string surname;
    string patronym;
    int age;
    string gender;
    string specialty;
    int course;
    int group;
    double average_score;
    int passes;
   
    int operator+( Student & other)
    {
        return age + other.age;
    };
    int operator *(Student& other) {
        return course * other.course;
    }
};
int main() {
    setlocale(LC_ALL, "rus");
    Date date1 = {7,1,1980};
    Date date2 = {17,2,1993};
    Date date3 = {9,1,1980};
    Date date4 = {17,2,1993};
    Date date5 = {18,2,1993};
    if (date2 < date5) std::cout << "истина" << std::endl; else std::cout << "ложь" << std::endl;
    if (date1 < date2) std::cout << "истина" << std::endl; else std::cout << "ложь" << std::endl;
    if (date1 > date2) std::cout << "истина" << std::endl; else std::cout << "ложь" << std::endl;
    if (date1 == date2) std::cout << "истина" << std::endl; else std::cout << "ложь" << std::endl;
    if (date1 == date3) std::cout << "истина" << std::endl; else std::cout << "ложь" << std::endl;
    if (date2 == date4) std::cout << "истина" << std::endl; else std::cout << "ложь" << std::endl;
    
    if (date5 > date3) std::cout << "истина" << std::endl; else std::cout << "ложь" << std::endl;
    Student first = {"Anna","Gritsenko","Aleksandrovna",17, "women","programmer",3,23,7.5,3};
    Student second = { "Alina","Gibdilina","Farhadovna",19, "women","teaher",1,3,8.6,14 };
    int r = first * second;
    cout << "first*second" << '\n' << r;
    cout << '\n';
    int e= first + second;
        cout << "first+second" << '\n' << e;
        cout << '\n';
        return 0;
}


