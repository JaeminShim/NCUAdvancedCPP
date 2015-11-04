// 1. this call_4
// 7-8page

#include <iostream>
#include <windows.h>
using namespace std;

// ��Ƽ ������ ������ Ŭ������ ������ �� ���ô�.
// �Ʒ� Ŭ������ ���̺귯�� ���� Ŭ������� �����մϴ�.

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
		// �ٽ� �����Լ� ȣ��
		Main();				// this->Main() ��, Main(this)�� �Ǿ�� �մϴ�.
		return 0;
	}
	*/

	// A. threadMain() �Լ��� static ��� �Լ��� ������ �ϴ� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	// B. static ��� �Լ��� this�� �����Ƿ� CreateThread()���� this�� �����ϴ� ������ ���.
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

// �Ʒ� Ŭ������ ���̺귯�� ������Դϴ�.

class MyThread : public Thread
{
public:
	virtual void Main() { cout << "Main" << endl; }
};

int main()
{
	MyThread t;
	t.run();		// �� ���� �����尡 �����Ǿ MyThread�� Main()�� �����ؾ� �մϴ�.

	Sleep(1000);	// ���� ������ ���� ����
}