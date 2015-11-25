// 6. begin - 195page

#include <iostream>
#include <algorithm>
#include <type_traits>
#include <vector>
using namespace std;

template<typename T> void show_imp(T& c, false_type)
{
	typename T::iterator p = c.begin();
	while (p != c.end())
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

template<typename T> void show_imp(T& c, true_type)
{
	auto p = c;
	while (p != c + extent<T,0>::value)
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

template<typename T> void show(T& c)
{
	show_imp(c, is_array<T>());
}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	vector<int> v(x, x + 10);

	show(v);	// v의 모든 요소를 출력
	show(x);
}
