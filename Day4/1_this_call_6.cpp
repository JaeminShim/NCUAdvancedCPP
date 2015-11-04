// 1. this call_6 - 9page

#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// C기반 GUI 함수를 객체지향으로 만들어 봅시다.

#include <map>

// 라이브러리 클래스
class CWnd
{
	int hwnd;	// 윈도우 번호

public:
	int GetHandle() const { return hwnd; }

public:
	void Create()
	{
		hwnd = IoMakeWindow(foo);
		this_map[hwnd] = this;
	}

	virtual void OnLButtonDown() {}

private:
	// A. 아래 함수가 static 멤버인 이유를 알아야 합니다. 
	static int foo(int h, int msg, int a, int b)
	{
		// 윈도우 번호를 가지고 자료구조에 보관된 this를 꺼낸다.
		CWnd* const self = this_map[h];
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->OnLButtonDown();		// 다시 가상함수 호출
			break;
		}
		return 0;
	}

	static map<int, CWnd*> this_map;	// 윈도우 핸들(번호)를 키값으로 윈도우 포인터(this)를 보관
};

// 사용자 클래스
class MyWindow : public CWnd
{
public:
	virtual void OnLButtonDown()
	{
		cout << "[" << GetHandle() << "] " << "LButton" << endl;
	}
};


int main()
{
	MyWindow w;
	w.Create();				// 이 순간 윈도우가 생성되어야 합니다.
							// LBUTTON누르면 "LButton" 출력 되어야 합니다.
	IoProcessMessage();		// 종료하지 말고 메시지를 처리해달라.
}

/*
							[this를 관리하는 방법]
							1. callback함수의 인자로 this
							2. 자료구조를 사용하여 this를 관리
									^
2차 API:		C++기반 클래스	static 멤버함수로 => this가 없다는 문제점 발생
---------------------------------------------------------------------
1차 API:		C기반 함수들		함수호출(다른함수이름(주소)) - callback 함수들
---------------------------------------------------------------------
모든 OS:		linux, Windows, MAC - C로 만듦
*/
