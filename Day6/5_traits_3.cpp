// 5. traits 3

#include <iostream>
#include <type_traits>
using namespace std;

// T�� Ư���� ���� �˰����� �ٲٰ� ���� ��.

void goo(true_type) { cout << "������ by goo" << endl; }
void goo(false_type) { cout << "������ �ƴ� by goo" << endl; }

template<typename T> void foo(T a)
{
	// T�� ������������ ���� �ڵ带 �����ϴ� 2���� ���
	// 1. value ����
	if (is_pointer<T>::value)
		cout << "������" << endl;
	else
		cout << "������ �ƴ�" << endl;

	// 2. �Լ� �����ε� ���
	goo(is_pointer<T>());
}

int main()
{
	int n = 10;
	foo(&n);
}
