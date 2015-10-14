// 8. Traits5 - 97page

#include <iostream>
using namespace std;

template <typename T> struct IsPointer		{ enum { value = false }; };
template <typename T> struct IsPointer<T*>	{ enum { value = true }; };

//-----------------------------------------------------------------------------
// �������� ���� �׷��� ���� ���� �Լ� �����ε� �մϴ�.
template <typename T, typename U> void printv_imp(T v, U tf)
{
}

template <typename T> void printv_imp<>(T v, ? )
{
	cout << "Is a pointer" << endl;
	cout << v << " : " << *v << endl;
}

template <typename T> void printv_imp(T v, ? )
{
	cout << "Is NOT a pointer" << endl;
	cout << v << endl;
}

// ����ڰ� ����ϴ� ����
template<typename T> void printv(T v)
{
	// �Ʒ�ó�� �ϸ�  if ���� ����ð� �����ϹǷ�
	// ������ �ð��� int ������ ���Ͽ� ���� 2�� �Լ��� ��� �����մϴ�.
	// ���� ������ ���� �߻�
	/*
	if (IsPointer<T>::value)
		printv_imp(v, [������ ����]);
	else
		printv_imp(v, [������ �ƴ� ����]);
	*/

	// �Ʒ�ó�� ��� �Լ��� ��������� ������ �ð��� �����ؾ� �մϴ�. - �Լ� �����ε� �ʿ�
	printv_imp(v, [���������� ����]);
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}