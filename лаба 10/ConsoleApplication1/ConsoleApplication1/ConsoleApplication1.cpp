#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#include <string>

int main()
{
	setlocale(LC_ALL, "");
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//определить количество целых чисел в std::vector равных заданному
	int target1 = 3;
	int num_items1 = std::count(v.begin(), v.end(), target1);
	std::cout << "число:" << target1 << "количество: " << num_items1 << '\n';

	//лямбда-выражение для подсчета элементов, кратных 3

	int num_item3 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	std::cout << "Количество элементов , кратных трем: " << num_item3 << '\n';
	std::cout << std::endl << "Лямбда, захват переменных" << std::endl;
	//лямбда-выражение, захват переменных
	for (auto i : v) [i]() {if (i % 3 == 0) std::cout << i << " "; }();
	std::cout << std::endl << "Лямбда с параметрами " << std::endl;
	// вывод значений , кратных 3. Значение будем передавать как параметр у обычной функции
	for (auto i : v) [](auto i) {if (i % 3 == 0) std::cout << i << " "; }(i);
	std::cout << std::endl << "Лямбда без параметров" << std::endl;
	// Вывод значений , кратных 3
		//Значения передаются через захват переменных при этом пропустим скобки для добавления параметров

	for (auto i : v) [i] {if (i % 3 == 0) std::cout << i << " "; }();

	// Пример использования лямбда-функции для сравнения строк
	auto longerString = [](const string& str1, const string& str2) {
		if (str1.length() == str2.length()) {
			cout << "Строки одинаковой длины: " << str1.length() << endl;
			return string(); // Возвращаем пустую строку, так как длины равны
		}
		cout << "Более длинная строка: ";
		return (str1.length() > str2.length()) ? str1 : str2;
		};

	cout << endl;
	string str1 = "ффффффффф", str2 = "ааа";
	auto result = longerString(str1, str2);
	if (!result.empty()) {
		cout << result << endl;
	}
}