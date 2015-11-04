// 1. this call_2
// - 멤버 함수와 함수 포인터

#include <iostream>
using namespace std;

// A. 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다.
// B. 일반 함수 포인터에 static 멤버 함수의 주소를 담을 수 있다.
// C. 멤버 함수 포인터를 만들고 사용하는 방법 - 6page
class Dialog
{
public:
	void Close() {}
};

void foo() {}

//int main()
//{
//	void(*f1)() = &foo;				// OK
//	void(*f2)() = &Dialog::Close;	// ERROR: this가 추가된다! [A]
//}

int main()
{
	// [C] 멤버 함수 포인터를 만들고 사용하는 방법

	// 멤버 함수의 주소를 담는 방법
	void (Dialog::*f)() = &Dialog::Close;

	//f();			// ERROR: 인자로 추가할 this가 없다!

	Dialog dlg;
	//dlg.f();		// 결국 dlg.Close();	// ERROR: 하지만 f는 Dialog에 없으므로 에러.
	//dlg.*f();		// ".*" 연산자		// ERROR: 연산자 우선순위 문제로 에러
	(dlg.*f)();		// OK
}
