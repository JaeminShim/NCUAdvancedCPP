// 6. value_type

#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
// 특수화 된 함수
void print_first_element(vector<int>& v)
{
	int n = v.front();
	cout << n << endl;
}
*/

/*
// 특수 컨테이너의 함수
template <typename T>
void print_first_element(vector<T>& v)
{
	T n = v.front();
	cout << n << endl;
}
*/

/*
// 일반화된 함수.
template <typename T>
void print_first_element(T& v)
{
	??? n = v.front();	// ???		// T는 컨테이너의 타입이므로 ???는 T로 치환 불가능
	cout << n << endl;
}
*/

/*
// 정답
template <typename T>
void print_first_element(T& v)
{
	typename T::value_type n = v.front();
	// - typename은 일반화 된 템플릿의 타입을 사용할 때 사용.
	// - typedef [type] value_type 은 "관례"
	cout << n << endl;
}
*/

// C++11 해결책 - 컴파일러는 front()의 리턴타입을 알 수 있다. (auto)
template <typename T>
void print_first_element(T& v)
{
	auto n = v.front();
	cout << n << endl;
}


int main()
{
	vector<int> v(10, 3);		// 10개를 3으로 초기화
	print_first_element(v);

	vector<double> v2(10, 3);	// 10개를 3으로 초기화
	list<double> l1(10, 3);
}

// template 기반 컨테이너는 자신이 저장하는 타입이 있습니다.
// 그런데 그 타입을 외부에서 알고 싶을 때가 있습니다.
// 위의 print_first_element()
// 그래서 아래처럼 만들었습니다.

/*
template<typename T> class list
{
public:
	typedef T value_type;
	//......
};

//list<int> s;
list<int>::value_type n;	// n은 결국 int 타입
*/
