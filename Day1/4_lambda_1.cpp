// 4_lambda_1 (20page)

#include <iostream>
#include <algorithm>	// sort()
#include <functional>	// STL�� �����ϴ� �Լ� ��ü��

int main()
{
	int x[10] = { -1,3,5,-7,-9,2,4,-6,8,-10 };

	// incremental sort
	std::sort(x, x + 10);

	// decremental sort
	// STL�� �����ϴ� �Լ� ��ü ��� - C++98 (1998�⿡ ǥ��ȭ �� ���ο� C++ ����)
	std::greater<int> f;
	std::sort(x, x + 10, f);

	// ���밪 ������������ ���� - C++11 (2011�⿡ ǥ��ȭ �� ���ο� C++ ����)
	// ���� ǥ���� (Lambda Expression): �Լ� ������ �Լ� ���ڷ� �����ϴ� ���
	// - []: introducer
	std::sort(x, x + 10, [](int a, int b) { return abs(a) < abs(b); });

	// �� �ڵ忡 ���ؼ� �����Ϸ��� ������ ���� �ڵ带 ������ (ǥ��)
	//---------------------------------------------------------------
	// Closure Object: ���� ǥ�������� ������� ��ü (C++������ �ǹ�)
	class Closure_Object
	{
	public:
		inline auto operator()(int a, int b) const	// �ζ���, ��� �Լ��� �������
		{
			return abs(a) < abs(b);
		}
	};
	Closure_Object cmp;
	std::sort(x, x + 10, cmp);
	//---------------------------------------------------------------

	for (auto n : x)
		std::cout << n << std::endl;
}