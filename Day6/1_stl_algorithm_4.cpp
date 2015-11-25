// 1. STL �˰��� 4 - 170page

#include <iostream>
using namespace std;

// 4. ���� �Ϲ�ȭ ����.
// �Ʒ� ó�� ����� 2������ ������ �ֽ��ϴ�. - 173page
// template <typename T> T* xfind(T* first, T* last, T value) { ... }
// 1) ã�� ������ Ÿ�԰� ����� Ÿ���� �����˴ϴ�.
//    double �迭���� int�� ã�� �� �����ϴ�.
// 2) T* ��� ������ �ݵ�� ��¥ �����͸� ��� �����մϴ�.
//    ����Ʈ �����͸� ����� �� �����ϴ�.

// �Ʒ� ó�� ������ �մϴ�.
template <typename T, typename U> T xfind(T first, T last, U value)
{
	while (first != last && *first != value)
		++first;
	// return first == last ? 0 : first;	// 0�� T�� ������ ����ϱ� ����� ��
	return first;
}

int main()
{
	double x[] = { 1,2,3,4,5,6,7,8,9,10 };
	double* p = xfind(x, x + 10, 15);

	//if (p == 0)
	if (p == x + 10)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}