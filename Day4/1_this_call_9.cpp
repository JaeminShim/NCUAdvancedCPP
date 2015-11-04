// 1. this call_9
// 다중 상속과 this, 다중 상속 클래스의 멤버 함수 포인터 - 13page

#include <iostream>
using namespace std;

class A
{
public:
	int a;
	void fa() { cout << this << endl; }
};

class B
{
public:
	int b;
	void fb() { cout << this << endl; }
};

class C : public A, public B
{
public:
	int c;
};

int main()
{
	C ccc;
	cout << &ccc << endl;		// 100 번지라고 할 때

	//---------------------------------------------
	void (C::*f)();	// 다중 상속 클래스의 멤버 함수 포인터
					/// struct { func_address, this_offset } 형태

	f = &C::fa;		// 호출하면 결과가 100
					/// { &fa, 0 }
	f = &C::fb;		// 호출하면 결과가 104
					/// { &fb, sizeof(A) }

	(ccc.*f)();		// 컴파일 타임에는 알 수 없음!
					/// f.func_address ( &ccc + f.this_offset )


	cout << sizeof(f) << endl;	// 덕분에 다중 상속 클래스의 멤버 함수 포인터는 8바이트(!)
	void (A::*fa)();
	cout << sizeof(fa) << endl;	// cf. 다중 상속 클래스가 아닌 멤버 함수 포인터는 4바이트
}