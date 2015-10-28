// 1. new - 28 page

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// [B]
// �Ʒ� �Լ��� �� ������ ������ - ��ƽ��ϴ�.
void* operator new(size_t sz, Point* p)
{
	return p;
}

// [C] - [B]�� ���� �Լ�
// placement new (��ġ���� new)
// �̹� �����ϴ� �޸��� �����ڸ� ȣ���ϱ� ���� ���� operator new() (C++ ǥ������ �����Ǿ� ����)
//void* operator new(size_t sz, void* p)
//{
//	return p;
//}

// [D] ���
// malloc		: �޸𸮸� �Ҵ��ϴ� �ڵ�
// new Point	: ���ο� �޸𸮿� ��ü�� �����ϴ� �ڵ� (�޸� �Ҵ� + ������ ȣ��)
// new(p) Point	: ���� �޸� p�� ��ü�� �����ϴ� �ڵ� (������ ȣ��)

// new�� �޸� �Ҵ��� �ƴ� ��ü�� �����Դϴ�. (��ü ������ �ǹ�)

int main()
{
	Point p(1, 2);

	// [B]
	// p ��ü�� ���Ͽ� �����ڸ� �ٽ� ȣ���ϴ� �ڵ�
	new(&p) Point;	// operator new(size_t sz, Point* p) ȣ��

	// [A]
	// calling constructor/destructor explicitly
	// p.Point(0, 0);	// ERROR - �������� ����� ȣ��	// �̰� �̻��� (���� ó���� ������ �־��ٰ� ��)
	p.~Point();			// OK - �Ҹ����� ����� ȣ��?		// �̰� ����
}