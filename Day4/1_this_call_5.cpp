// 1. this call_5

#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// C��� GUI �Լ�

int foo(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		cout << "LBUTTON" << endl;
		break;
	}
	return 0;
}

int main()
{
	int h1 = IoMakeWindow(foo);
	int h2 = IoMakeWindow(foo);

	IoProcessMessage();			// �������� ���� �޽����� ó���ش޶�.
}