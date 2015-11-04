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

// xget<>()�� ����
template<int N, typename T>
[N��°���Ÿ��] xget(T& tp)
{
	// tp��� Ʃ���� N��° ��Ҹ� �����ؾ� �Ѵ�.
	return ([N��°�θ�Ÿ��&]tp).value;
}

int main()
{
	//         �θ� xtuple<char>					// value = 'a' ����
	// �θ� xtuple<double, char>					// value = 2.2 ����
	xtuple<int, double, char> t3(1, 2.2, 'a');	// value = 1 ����

	double n = xget<1>(t3);	// t3�� �ι�° ��� ������
}