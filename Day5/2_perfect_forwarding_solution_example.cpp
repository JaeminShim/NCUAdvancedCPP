// 2. �Ϻ��� ������ - ���� - 146page

#include <iostream>
#include <memory>
using namespace std;

/*
class Point
{
	int x, y;
public:
	Point(int a, int b) {}
};

int main()
{
	// shared_ptr�� �޸� ����ȭ (��ü �޸� ����, ref_count �޸� ����)

	shared_ptr<Point> p1(new Point(1, 1));	// ��ü �޸�, ���� ����� �޸� ���� �Ҵ�
	//shared_ptr<Point> p2 = p1;

	// �Ʒ�ó�� �ϸ� sizeof(Point) + sizeof(�������) ���� ��ŭ �� ���� �޸� �Ҵ� �˴ϴ�.
	shared_ptr<Point> p2 = make_shared<Point>(1, 2);
}
*/

#include <thread>		// C++11 ������ 

void foo(int a, int b, int c)
{
}

int main()
{
	thread t(&foo, 1, 2, 3);	// �� ���� ���ο� �����尡 �����Ǿ� foo ����

	t.join();					// ������ ���� ���
}
