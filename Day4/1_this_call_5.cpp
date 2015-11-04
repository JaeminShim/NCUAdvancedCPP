// 1. this call_5

#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// C기반 GUI 함수

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

	IoProcessMessage();			// 종료하지 말고 메시지를 처리해달라.
}