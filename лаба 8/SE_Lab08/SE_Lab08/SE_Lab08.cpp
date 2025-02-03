#include <iostream>
#include <cstring>
using namespace std;

int defaultparm(int a, int b, int c, int d , int e , int f = 7, int g = 5) {

    int count = 7;
    int sum = a + b + c + d + e + f + g;
    
    int average = sum / count;
    return average;
}

int main() {
    setlocale(0, "rus");

    double result5 = defaultparm(1, 2, 3, 4, 5);
    double result7 = defaultparm(1, 2, 3, 4, 5, 6, 7);

    cout << "Среднее арифметическое 5 параметров: " << result5 << endl;
    cout << "Среднее арифметическое 7 параметров: " << result7 << endl;
    char str1[90] = "Press Enter";
    char str2[90] = "to continue";
    strncat(str1,str2,6);
    cout << str1;
    return 0;
}
