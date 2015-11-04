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

//----------------------------------------------------------------
// tuple<T, Types...>의 N번째 요소의 타입을 구하는 메타 함수
// NOTE! tuple에 대한 무언가를 만들 때에는 tuple<T, Types...>를 사용해야 추론이 가능.

template <int N, typename T, typename ... Types> struct xtuple_element {};

// N이 0일 때를 위한 부분 전문화
template <typename T, typename ... Types>
struct xtuple_element<0, xtuple<T, Types...>>
{
	typedef T elementType;
	typedef typename xtuple<T, Types...> tupleType;
};

// N이 0이 아닐 때를 위한 부분 전문화
template <int N, typename T, typename ... Types>
struct xtuple_element<N, xtuple<T, Types...>>
{
	typedef typename xtuple_element<N - 1, xtuple<Types...>>::elementType	elementType;
	typedef typename xtuple_element<N - 1, xtuple<Types...>>::tupleType		tupleType;
};

// [N번째요소타입] => elementType
// Example of xtuple_element
//xtuple_element<0, xtuple<int, double, char>>::elementType		// int
//xtuple_element<1, xtuple<int, double, char>>::elementType		// double

// [N번째부모타입] => tupleType
//xtuple_element<0, xtuple<int, double, char>>::tupleType		// xtuple<int, double, char>
//xtuple_element<1, xtuple<int, double, char>>::tupleType		// xtuple<double, char>

// xget<>()의 원형
template<int N, typename T>
typename xtuple_element<N, T>::elementType xget(T& tp)
{
	// tp라는 튜플의 N번째 요소를 리턴해야 한다.
	return ((typename xtuple_element<N, T>::tupleType&)tp).value;
}

int main()
{
	//         부모 xtuple<char>					// value = 'a' 보관
	// 부모 xtuple<double, char>					// value = 2.2 보관
	xtuple<int, double, char> t3(1, 2.2, 'a');	// value = 1 보관

	auto n = xget<1>(t3);	// t3의 두번째 요소 꺼내기
	cout << n << endl;
}