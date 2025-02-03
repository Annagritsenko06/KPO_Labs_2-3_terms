#pragma once
#ifndef CALL_H
#define CALL_H

namespace Call {
	int _cdecl funcA(int x, int y, int c);
	int _stdcall funcB(int& z1, int z2, int z3);
	int _fastcall funcC(int p1, int p2, int p3, int p4);
}

#endif 