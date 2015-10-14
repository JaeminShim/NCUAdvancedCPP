// 8. Traits5 - 97page

#include <iostream>
using namespace std;

template <typename T> struct IsPointer		{ enum { value = false }; };
template <typename T> struct IsPointer<T*>	{ enum { value = true }; };

// �Ʒ� ���ø��� �� ������ ������. - 98page ���� �ҽ�
// int�� Ÿ��ó�� �������! -> ������ �ð��� �����ε��ϵ���!
template <int N> struct int2type
{
	enum { value = N };
};

/*
int main()
{
	// 0, 1�� ��� int�̱� ������ �� �� ���� �Լ��� ȣ��
	foo(0);
	foo(1);

	int2type<0> t0;
	int2type<1> t1;

	// t0, t1�� ���� �ٸ� Ÿ���̱� ������ ���� �ٸ� �Լ��� ȣ��
	foo(t0);
	foo(t1);
}
*/

// ���� �̸��� ������� ������ �ڵ� �������� ����
template <typename T> void printv_imp(T v, int2type<1>)
{
	cout << "Is a pointer" << endl;
	cout << v << " : " << *v << endl;
}

template <typename T> void printv_imp(T v, int2type<0>)
{
	cout << "Is NOT a pointer" << endl;
	cout << v << endl;
}

// ����ڰ� ����ϴ� ����
template<typename T> void printv(T v)
{
	// int2type<IsPointer<T>::value>�� Ÿ��!
	printv_imp(v, int2type<IsPointer<T>::value>());
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}
