// 1. this call_3
// - 객체지향 디자인과 this 문제 - 7page

#include <iostream>
#include <windows.h>
using namespace std;

// 윈도우에서 스레드 함수
DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, "A", 0, 0);	// Windows 스레드 함수
}
