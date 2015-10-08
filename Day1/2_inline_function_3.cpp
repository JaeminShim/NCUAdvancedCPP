// 2_�ζ����Լ�_3 (16page)

// ���̺귯�� �Լ��� ����: ����, ������(��å�� ����)
// ������ �ʴ� ��ü �帧����(�˰���) ���ϴ� �κ�(��å)�� ã�Ƽ� �и��ؾ� �Ѵ�.
// => ���ϴ� ���� �Լ� ����ȭ �Ѵ�.

#include <algorithm>
#include <iostream>

void Sort(int* x, int n, bool (*cmp)(int,int))
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(x[i], x[j]))	// 2�� ����
				std::swap(x[i], x[j]);
		}
	}
}

void Print(int* x, int n)
{
	int i = -1;
	while (++i < n)
		std::cout << x[i] << ' ';
	std::cout << std::endl;
}

inline bool cmp_incr(int a, int b) { return a < b; }
inline bool cmp_decr(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Sort(x, _countof(x), cmp_incr);
	Print(x, _countof(x));

	Sort(x, _countof(x), cmp_decr);
	Print(x, _countof(x));

	auto cmp_lamda_incr = [](auto a, auto b) { return a > b; };
	Sort(x, _countof(x), cmp_lamda_incr);
}