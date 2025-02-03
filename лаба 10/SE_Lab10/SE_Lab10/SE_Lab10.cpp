//Разработать лямбда - функцию, которая принимает две строки и возвращает
//ту строку, которая длиннее.

#include <iostream>
#include <string>

using namespace std;



int main() {
    setlocale(0, "rus");

    // Пример использования лямбда-функции для сравнения строк
    auto longerString = [](const string& str1, const string& str2) {
        return (str1.length() > str2.length()) ? str1 : str2;
        };

    string str1 = "Hhhhhh", str2 = "ww";
    cout << "Более длинная строка: " << longerString(str1, str2) << endl;

        auto concatenateStrings = [](const std::string& str1, const std::string& str2) {
            return str1 + str2;
            };

      string result = concatenateStrings("I like ", "banana!");
     cout << "Concatenated string: " << result << endl;

    return 0;
}