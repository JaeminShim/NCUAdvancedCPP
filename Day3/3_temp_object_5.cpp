// 3. �ӽð�ü - 35 page~
// ���� ������ �Լ� ����

#include <iostream>
using namespace std;

struct Point
{
	int x, y;
};

Point p = { 1, 2 };

//// [A]
//Point foo()		// �� ����: ���Ͽ� �ӽð�ü�� ����
//{
//	return p;	// ������ü ���� - �ӽð�ü�� ���� �����Ѵ�.
//}

// [B]
Point& foo()	// ���� ����: ���Ͽ� �ӽð�ü�� ������ ����� �ǹ�
{
	return p;
}

int main()
{
	foo().x = 10;	// [A] ����??? - X (but OK in MSVC) - �ӽð�ü�� �� ���� - primitive type�� �����غ���
					//				=> �ӽ� ��ü�� lvalue�� �� �� ����!
	cout << p.x << endl;
}