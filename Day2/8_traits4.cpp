// 8. Traits4 - 97page

#include <iostream>
using namespace std;

template <typename T> struct IsPointer		{ enum { value = false }; };
template <typename T> struct IsPointer<T*>	{ enum { value = true }; };

// print variable
template<typename T> void printv(T v)
{
	if (IsPointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int n = 10;
	printv(n);	// ERROR -  T�� �����Ͱ� �ƴϹǷ� if()���� false�� ��������� ������ �������� ����.
				//         ���� if()�� ���� *v ���� ������ �߻�.
	printv(&n);	// OK
}