// 8. Traits2 - 96page

#include <iostream>
using namespace std;

//------------------------------------------------------
// Trait : T�� �پ��� Ư���� �����ϴ� ��Ÿ�Լ�
//------------------------------------------------------
// [����� ��] (96page)
// - primary template: false ���� (value = false��� �ǹ�)
// - �κ� ����ȭ ����: true ����
//------------------------------------------------------

// T�� ���������� �����ϴ� ��Ÿ �Լ�
template <typename T> struct IsPointer
{
	enum { value = false };
};

template <typename T> struct IsPointer<T*>
{
	enum { value = true };
};

template <typename T> void foo(const T& a)
{
	if (IsPointer<T>::value)
		cout << "Is a pointer" << endl;
	else
		cout << "Is not a pointer" << endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}