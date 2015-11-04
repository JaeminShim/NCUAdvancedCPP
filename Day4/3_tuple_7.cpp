// 3. Tuple - 4_member_name_confliction ����!

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

	enum { N = base::N + 1 };	// ���� ����
};

// ���ڰ� 1���� tuple�� ���� �κ� ����ȭ
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
// tuple<T, Types...>�� N��° ����� Ÿ���� ���ϴ� ��Ÿ �Լ�
// NOTE! tuple�� ���� ���𰡸� ���� ������ tuple<T, Types...>�� ����ؾ� �߷��� ����.

template <int N, typename T, typename ... Types> struct xtuple_element {};

// N�� 0�� ���� ���� �κ� ����ȭ
template <typename T, typename ... Types>
struct xtuple_element<0, xtuple<T, Types...>>
{
	typedef T elementType;
	typedef typename xtuple<T, Types...> tupleType;
};

// N�� 0�� �ƴ� ���� ���� �κ� ����ȭ
template <int N, typename T, typename ... Types>
struct xtuple_element<N, xtuple<T, Types...>>
{
	typedef typename xtuple_element<N - 1, xtuple<Types...>>::elementType	elementType;
	typedef typename xtuple_element<N - 1, xtuple<Types...>>::tupleType		tupleType;
};

// [N��°���Ÿ��] => elementType
// Example of xtuple_element
//xtuple_element<0, xtuple<int, double, char>>::elementType		// int
//xtuple_element<1, xtuple<int, double, char>>::elementType		// double

// [N��°�θ�Ÿ��] => tupleType
//xtuple_element<0, xtuple<int, double, char>>::tupleType		// xtuple<int, double, char>
//xtuple_element<1, xtuple<int, double, char>>::tupleType		// xtuple<double, char>

// xget<>()�� ����
template<int N, typename T>
typename xtuple_element<N, T>::elementType xget(T& tp)
{
	// tp��� Ʃ���� N��° ��Ҹ� �����ؾ� �Ѵ�.
	return ((typename xtuple_element<N, T>::tupleType&)tp).value;
}

int main()
{
	//         �θ� xtuple<char>					// value = 'a' ����
	// �θ� xtuple<double, char>					// value = 2.2 ����
	xtuple<int, double, char> t3(1, 2.2, 'a');	// value = 1 ����

	auto n = xget<1>(t3);	// t3�� �ι�° ��� ������
	cout << n << endl;
}