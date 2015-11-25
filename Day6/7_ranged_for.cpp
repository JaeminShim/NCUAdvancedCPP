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

	// 위 코드는 컴파일 되면 아래 코드로 변경됩니다.
	/* // C++ 표준 문서에 기록되어 있음!
	for (auto it = begin(p); it != end(p); ++it)
	{
		auto n = *it;
		cout << n << endl;
	}
	*/
}