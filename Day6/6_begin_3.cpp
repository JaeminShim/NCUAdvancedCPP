// 6. begin 3 - 199page

#include <iostream>
#include <algorithm>
#include <type_traits>
#include <vector>
using namespace std;

// C++11 ranged for 사용
template<typename T> void show(T& c)
{
	for(auto n : c)
		cout << n << " ";
	cout << endl;
}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	vector<int> v(x, x + 10);

	show(v);	// v의 모든 요소를 출력
	show(x);
}
