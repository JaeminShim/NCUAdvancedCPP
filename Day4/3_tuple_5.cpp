// 3. Tuple - 4_member_name_confliction 참고!

#include <iostream>
using namespace std;

template<typename T, typename ... Types>
class xtuple : public xtuple<Types...>
{
	typedef xtuple<Types...> base;

public:
	T value;

	xtuple() {}
	xtuple(const T& a, const Types&... args) : base(args...), value(a) { }

	enum { N = base::N + 1 };	// 갯수 관리
};

// 인자가 1개인 tuple을 위한 부분 전문화
template<typename T>
class xtuple<T>
{
public:
	T value;

	xtuple() {}
	xtuple(const T& a) : value(a) { }

	enum { N = 1 };
};

int main()
{
	//         부모 xtuple<char>					// value = 'a' 보관
	// 부모 xtuple<double, char>					// value = 2.2 보관
	xtuple<int, double, char> t3(1, 2.2, 'a');	// value = 1 보관

	cout << t3.value << endl;							// 1
	cout << ((xtuple<double, char>&)t3).value << endl;	// 2.2
	cout << ((xtuple<char>&)t3).value << endl;			// 'a'
}