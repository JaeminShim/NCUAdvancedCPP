// 1. this call_3
// - ��ü���� �����ΰ� this ���� - 7page

#include <iostream>
#include <windows.h>
using namespace std;

// �����쿡�� ������ �Լ�
DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, "A", 0, 0);	// Windows ������ �Լ�
}
