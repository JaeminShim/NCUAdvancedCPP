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
};

void foo(Point p)
{
}

int main()
{
	//{
	//	Point p;	// p�� �ܼ��� �Ʒ� �Լ��� �����ϱ� ���� �뵵
	//	foo(p);
	//	// ...		// ���� p �� �������
	//}				// p �Ҹ�

	foo(Point());	// �Լ� ���ڷθ� ��ü�� �����Ҷ��� �ӽ� ��ü�� ���� ����Ѵ�.
					// 2���� �ҽ� �� printv( a, int2type<>() );
}