// 7. ranged for - 203 page

#include <iostream>
using namespace std;

struct Point3d
{
	int x, y, z;

	Point3d(int a, int b, int c) : x(a), y(b), z(c) {}
};
int* begin(Point3d& p) { return &(p.x); }
int* end(Point3d& p)   { return &(p.z) + 1; }

int main()
{
	Point3d p(1, 2, 3);

	for (auto n : p)
		cout << n << endl;

	// �� �ڵ�� ������ �Ǹ� �Ʒ� �ڵ�� ����˴ϴ�.
	/* // C++ ǥ�� ������ ��ϵǾ� ����!
	for (auto it = begin(p); it != end(p); ++it)
	{
		auto n = *it;
		cout << n << endl;
	}
	*/
}