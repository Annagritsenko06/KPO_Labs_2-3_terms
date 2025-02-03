#include "Varparm.h"
#include <iostream>
#include <cstdarg>
#include <climits>
#include <cfloat>

using namespace std;

namespace Varparm
{
    int ivarparm(int count, ...) {
        va_list args; 
        va_start(args, count);
        int result = 1; 
        for (int i = 0; i < count; ++i) { 
            result *= va_arg(args, int); 
        }
        va_end(args); 
        return result;
    }

    int svarparm(short count, ...) {
        va_list args; 
        va_start(args, count); 
        int max = SHRT_MIN; 
        for (short i = 0; i < count; ++i) { 
            int val = va_arg(args, int); 
            if (val > max) 
                max = val; 
        }
        va_end(args); 
        return max;
    }

    double fvarparm(float max, ...) {
        va_list args; 
        va_start(args, max); 
        double sum = 0;
        float val = 0; 
        while ((val = va_arg(args, double)) < max) { 
            sum += val; 
        }
        va_end(args); 
        return sum;
    }

    double dvarparm(double max, ...) {
        va_list args; 
        va_start(args, max); 
        double sum = 0;
        double val = 0; 
        while ((val = va_arg(args, double)) < max) { 
            sum += val; 
        }
        va_end(args); 
        return sum;
    }
}

int main()
{
	setlocale(LC_ALL, "rus");

    cout << "ivarparm 1 параметр: " << Varparm::ivarparm(1, 5) << endl;
    cout << "ivarparm 2 параметра: " << Varparm::ivarparm(2, 2, 3) << endl;
    cout << "ivarparm 3 параметра: " << Varparm::ivarparm(3, 2, 3, 4) << endl;
    cout << "ivarparm 7 параметров: " << Varparm::ivarparm(7, 1, 2, 3, 4, 5, 6, 7) << endl;

    
    cout << "svarparm 1 параметр: " << Varparm::svarparm(1, 5) << endl;
    cout << "svarparm 2 параметра: " << Varparm::svarparm(2, 2, 3) << endl;
    cout << "svarparm 3 параметра: " << Varparm::svarparm(3, 2, 3, 4) << endl;
    cout << "svarparm 7 параметров: " << Varparm::svarparm(7, 1, 2, 3, 4, 5, 6, 7) << endl;

    
    cout << "fvarparm: " << Varparm::fvarparm(FLT_MAX, 1.1f, 2.2f, 3.3f, FLT_MAX) << endl;

    
    cout << "dvarparm: " << Varparm::dvarparm(DBL_MAX, 1.1, 2.2, 3.3, DBL_MAX) << endl;

	system("pause");
	return 0;
}