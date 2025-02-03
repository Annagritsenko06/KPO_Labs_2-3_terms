#include "Call.h"
#include <iostream>
#include <locale>
#include <cstdarg>

namespace Call {
	int _cdecl funcA(int x, int y, int z) {return x + y + z;}

	int _stdcall funcB(int& z1, int z2, int z3) {return z1 * z2 * z3;}

	int _fastcall funcC(int p1, int p2, int p3, int p4) {return p1 + p2 + p3 + p4;}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	int k1, k2, k3;
	int z1 = 1; 
	k1 = Call::funcA(1, 2, 3);
	k2 = Call::funcB(z1, 2, 3); 
	k3 = Call::funcC(1, 2, 3, 4);

	// Вывод результатов в консоль
	std::cout << "Результат вызова функции funcA: " << k1 << std::endl;
	std::cout << "Результат вызова функции funcB: " << k2 << std::endl;
	std::cout << "Результат вызова функции funcC: " << k3 << std::endl;

	system("pause");
	return 0;
}