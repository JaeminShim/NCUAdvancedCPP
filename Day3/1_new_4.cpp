// 1. new - 28 page

// �� �����ڸ� ��������� ȣ���ϴ°�?
// 1. ���ϴ�
// 2. vector�� ���� ȿ���� �޸� ����
// 3. ���� generic �˰��� ����

#include <iostream>
#include <new> // placement new�� ����ϱ� ����
using namespace std;

class Point
{
	int x, y;

public:
	Point(int a, int b) {}
};

int main()
{
	// [A] Point�� ���� �ϳ� ����� ������
	auto p1 = new Point(1, 2);

	// [B] ���� Point�� 10���� ����� ������
	//Point* p2 = new Point[10];		// ERROR - �޸� �Ҵ�� ������ ȣ���� ���ÿ� �Ͼ�� ����
	//Point* p2 = new Point(1, 2)[10];	// ERROR - ������ ���� �Ұ���
	Point* p2 = static_cast<Point*>(operator new (sizeof(Point) * 10));		// �޸� �Ҵ�
	// �Ҵ�� �޸𸮸� ��ü�� �����ϱ� ���� ������ ȣ�� - placement new ���
	for (int i = 0; i < 10; ++i)
		new (&p2[i]) Point(1, 2);

	// [C] ���ÿ� Point�� 10���� ����� ������.
	char buf[sizeof(Point) * 10];
	Point* p3 = reinterpret_cast<Point*>(buf);
	for (int i = 0; i < 10; ++i)
		new (&p3[i]) Point(1, 2);
}