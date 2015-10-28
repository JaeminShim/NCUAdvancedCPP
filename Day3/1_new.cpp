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

int main()
{
	// new Ű������ ��Ȯ�� ���� ���
	// A. operator new()��� �Լ��� ����ؼ� �޸� �Ҵ�
	// B. A�� �����ϰ� ��ü��� ������ ȣ��
	// C. �޸� �ּҸ� �ش� Ÿ������ ĳ�����Ͽ� ����.
	//Point* p = new Point;
	//delete p;

	// ������ ȣ�� ���� �޸𸮸� �Ҵ��ϴ� ��� (operator new() ���)
	Point* p = static_cast<Point*>(operator new(sizeof(Point)));
	operator delete(p);	// �Ҹ��� ȣ�� ����
}