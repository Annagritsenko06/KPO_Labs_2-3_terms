#pragma once
#include <iostream>
#include <Windows.h>
#include "Dictionary.h"

//#define TEST_DICTIONARY
#define TEST_ADDENTRY_04
//#if defined(TEST_ADDENTRY_04)

//#define TEST_CREATE_01
//#define TEST_CREATE_02
//#define TEST_ADDENTRY_03

//#define TEST_GETENTRY_05 
//#define TEST_GETENTRY_06
//#define TEST_UPDENTRY_07
//#define TEST_UPDENTRY_08 
//#define TEST_PRINT_09 


#if (defined TEST_CREATE_01 + defined TEST_CREATE_02 + defined TEST_ADDENTRY_04 + defined TEST_ADDENTRY_03 + defined TEST_DICTIONARY + defined TEST_GETENTRY_05 + defined TEST_GETENTRY_06 + defined TEST_UPDENTRY_07 + defined TEST_UPDENTRY_08 + defined TEST_PRINT_09>1)
#error Нельзя устанавливать больше одного макроса для тестирования
#endif
//#endif