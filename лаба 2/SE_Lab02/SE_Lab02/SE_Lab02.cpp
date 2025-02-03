#include <iostream>
#include <Windows.h>
using namespace std;

int sum(int x, int y) { return x + y; };

int main() {
	int n=6;
	int X, Y, Z;
	float S;
	X = 9 + n;
	Y = 10 + n;
	Z = 11 + n;
	S = 1.0 + n;
	bool x1 = true;
	bool x2 =false;
	char secondLetterEng = 'r';
	char secondLetterRus = 'р';
	wchar_t firstLetterEng = L'G';
	wchar_t firstLetterRus = L'Г';
	short q1 = 15;// 0F
	short q2 = -15;//F1 (11110001)
	short max = 0x7FFF;//Самое большое положительное число типа short
	short min = 0x8000;//Самое маленькое отрицательное число типа short
	unsigned short max_unshort = 0xFFFF;//Самое большое число типа unsigned short 
	unsigned short min_unshort = 0x0000;//Самое малое число типа unsigned short 
	int posY = 16;//10 
	int negY = -16;//F0 (11110000) 
	int max_int = 0x7FFFFFFF;
	int min_int = 0x80000000;
	unsigned int max_unint = 0xFFFFFFFF;
	unsigned int min_unint = 0x00;
	long posZ = 17;//11 
	long negZ = -17;//EF (11101111)
	long max_long = 0x7FFFFFFF;
	long min_long = 0x80000000;
	unsigned long max_unlong = 0xFFFFFFFF;
	unsigned long min_unlong = 0x00;
	float posS = 7.0;//40E00000(0100 0000 1110 0000 0000 0000 0000 0000) 
	float negS = -7.0;//C0E00000(1100 0000 1110 0000 0000 0000 0000 0000)
	float ps = 7.0;
	float ns = -7.0;
	float positive_inf = ps / 0;//inf
	float negative_inf = ns / 0;//-inf
	float ind = positive_inf / negative_inf;//-nan(ind)  
	double r = 9.11;//4111C28F(0100 0001 0001 0001 1100 0010 1000 1111)
	char* psecondLetterEng = &secondLetterEng;
	wchar_t* pfirstLetterEng = &firstLetterEng;
	short* pq1 = &q1;
	int* pn = &n;
	float* pS = &S;
	double* pr = &r;

	psecondLetterEng += 3;
	pfirstLetterEng += 3;
	pq1 += 3;
	pn += 3;
	pS += 3;
	pr += 3;

	int (*fun)(int, int);
	fun = sum;
	int result = fun(4, 5);
	
	int rar  = 0x10000000;
}

