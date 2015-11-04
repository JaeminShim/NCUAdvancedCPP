// 1. this call_6 - 9page

#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// C��� GUI �Լ��� ��ü�������� ����� ���ô�.

#include <map>

// ���̺귯�� Ŭ����
class CWnd
{
	int hwnd;	// ������ ��ȣ

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
	// A. �Ʒ� �Լ��� static ����� ������ �˾ƾ� �մϴ�. 
	static int foo(int h, int msg, int a, int b)
	{
		// ������ ��ȣ�� ������ �ڷᱸ���� ������ this�� ������.
		CWnd* const self = this_map[h];
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->OnLButtonDown();		// �ٽ� �����Լ� ȣ��
			break;
		}
		return 0;
	}

	static map<int, CWnd*> this_map;	// ������ �ڵ�(��ȣ)�� Ű������ ������ ������(this)�� ����
};

// ����� Ŭ����
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
	w.Create();				// �� ���� �����찡 �����Ǿ�� �մϴ�.
							// LBUTTON������ "LButton" ��� �Ǿ�� �մϴ�.
	IoProcessMessage();		// �������� ���� �޽����� ó���ش޶�.
}

/*
							[this�� �����ϴ� ���]
							1. callback�Լ��� ���ڷ� this
							2. �ڷᱸ���� ����Ͽ� this�� ����
									^
2�� API:		C++��� Ŭ����	static ����Լ��� => this�� ���ٴ� ������ �߻�
---------------------------------------------------------------------
1�� API:		C��� �Լ���		�Լ�ȣ��(�ٸ��Լ��̸�(�ּ�)) - callback �Լ���
---------------------------------------------------------------------
��� OS:		linux, Windows, MAC - C�� ����
*/
