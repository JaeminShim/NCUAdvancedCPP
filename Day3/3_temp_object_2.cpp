// 3. �ӽð�ü - 35 page~

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	//Point p;	// ������ü. �̸��� �ְ�, scope�� ��� �� �ı�

	cout << "AAA" << endl;
	Point();	// �ӽð�ü ����. �̸��� ����, ������ ������ �ı��ȴ�.
				// C++ ǥ�ع����� ���� ��޵� ���.
				// ��Ī: "unnamed object"
	cout << "BBB" << endl;
}