// 3. �ӽð�ü - 35 page~
// �ӽ� ��ü�� �Լ� ����

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
	Point(const Point& p) { cout << "Point() ���������" << endl; }
};

// [A]
Point foo()
{
	// [C]
	// compile with "Release" configuration
	// NRVO (Named RVO)
	// �̸� �ִ� ��ü�� ����ȭ �� �� �� �ִٴ� ���
	// http://cafe.naver.com/cppmaster �� <C++ Idioms>���� NRVO �׸� ����. (���� �� �������� ���Ͽ�)
	// ��� �����Ϸ��� NRVO�� ���������� �ʽ��ϴ�.

	Point p;
	cout << "foo" << endl;
	return p;
}

//// [B]
//Point foo()
//{
//	cout << "foo" << endl;
//
//	// �ӽð�ü�� ����� ���� - ���Ͽ� �ӽð�ü�� �����ȴ�.
//	// RVO (Return Value Optimization)�̶�� �̸��� ���� ���
//	return Point();
//}

int main()
{
	Point p1;
	p1 = foo();
	cout << "end" << endl;

	// [A]
	// �������
	// 1. Point() ������ - p1
	// 2. Point() ������ - p
	// 3. foo
	// 4. Point() ��������� - foo ����
	// 5. �Ҹ��� - p
	// 6. �Ҹ��� - foo ����
	// 7. end
	// 8. �Ҹ��� - p1

	// [B]
	// �����ڿ� �Ҹ��� 2ȸ���� ȣ��
}
