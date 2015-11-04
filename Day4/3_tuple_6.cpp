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

// xget<>()의 원형
template<int N, typename T>
[N번째요소타입] xget(T& tp)
{
	// tp라는 튜플의 N번째 요소를 리턴해야 한다.
	return ([N번째부모타입&]tp).value;
}

int main()
{
	//         부모 xtuple<char>					// value = 'a' 보관
	// 부모 xtuple<double, char>					// value = 2.2 보관
	xtuple<int, double, char> t3(1, 2.2, 'a');	// value = 1 보관

	double n = xget<1>(t3);	// t3의 두번째 요소 꺼내기
}