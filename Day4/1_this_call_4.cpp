// 1. this call_4
// 7-8page

#include <iostream>
#include <windows.h>
using namespace std;

// 멀티 스레드 개념을 클래스로 디자인 해 봅시다.
// 아래 클래스는 라이브러리 내부 클래스라고 가정합니다.

class Thread
{
public:
	virtual void Main() = 0;		// void Main(Thread* const this)

	/*
	void run()
	{
		CreateThread(0, 0, threadMain, 0, 0, 0);
	}

	DWORD __stdcall threadMain(void* p)
	{
		// 다시 가상함수 호출
		Main();				// this->Main() 즉, Main(this)가 되어야 합니다.
		return 0;
	}
	*/

	// A. threadMain() 함수를 static 멤버 함수로 만들어야 하는 이유를 정확히 알아야 합니다.
	// B. static 멤버 함수는 this가 없으므로 CreateThread()에서 this를 전달하는 디자인 기법.
	void run()
	{
		CreateThread(0, 0, threadMain, this, 0, 0);
	}

	static DWORD __stdcall threadMain(void* p)
	{
		Thread* const self = static_cast<Thread*>(p);
		self->Main();
		return 0;
	}
};

// 아래 클래스는 라이브러리 사용자입니다.

class MyThread : public Thread
{
public:
	virtual void Main() { cout << "Main" << endl; }
};

int main()
{
	MyThread t;
	t.run();		// 이 순간 스레드가 생성되어서 MyThread의 Main()을 실행해야 합니다.

	Sleep(1000);	// 메인 스레드 종료 지연
}