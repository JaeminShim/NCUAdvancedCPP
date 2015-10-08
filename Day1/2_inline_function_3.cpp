// 2_인라인함수_3 (16page)

// 라이브러리 함수의 조건: 성능, 유연성(정책의 변경)
// 변하지 않는 전체 흐름에서(알고리즘) 변하는 부분(정책)을 찾아서 분리해야 한다.
// => 변하는 것을 함수 인자화 한다.

#include <algorithm>
#include <iostream>

void Sort(int* x, int n, bool (*cmp)(int,int))
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(x[i], x[j]))	// 2중 루프
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