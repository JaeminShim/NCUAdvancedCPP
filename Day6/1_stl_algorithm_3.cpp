// 1. STL �˰����� 3 - 170page

#include <iostream>
using namespace std;

// 3. ��� Ÿ���� �迭�� �˻� �����ϰ� ����. => template ����

template <typename T>
T* xfind(T* first, T* last, T value)
{
	while (first != last && *first != value)
		++first;
	return first == last ? 0 : first;
}

int main()
{
	double x[] = { 1,2,3,4,5,6,7,8,9,10 };
	double* p = xfind(x, x + 10, 5.0);

	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}