// 2. Variadic template - C++11/14 �̾߱�

#include <iostream>
using namespace std;

// C++ ǥ�� ���̺귯���� tuple�� ������ϴ�. (2008�� �� ����)
#include <tuple>

int main()
{
	tuple<int, int, int> t3(1, 2, 3);
	tuple<int, int> t2(1, 2);

	// tuple�� �ְ� ������
	get<0>(t3) = 10;
	cout << get<0>(t3) << endl;
}
