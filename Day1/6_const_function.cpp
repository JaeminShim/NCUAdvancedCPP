// <6> ����Լ� (65 page)

#include <iostream>

using namespace std;

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	void print() const
	{
		//x = 0;	// ERROR: ��� �Լ������� ��� ����� ��� ���.
		cout << x << ", " << y << endl;
	}
};

int main()
{
	const Point p(1, 2);	// ��� ��ü�� ������ ���ô�.
	p.x = 10;				// ERROR: const ��ü�� member variable
	p.set(10, 20);			// ERROR: const ��ü�� non-const member function
	p.print();
}