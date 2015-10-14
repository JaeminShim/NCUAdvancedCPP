// 6. value_type

#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
// Ư��ȭ �� �Լ�
void print_first_element(vector<int>& v)
{
	int n = v.front();
	cout << n << endl;
}
*/

/*
// Ư�� �����̳��� �Լ�
template <typename T>
void print_first_element(vector<T>& v)
{
	T n = v.front();
	cout << n << endl;
}
*/

/*
// �Ϲ�ȭ�� �Լ�.
template <typename T>
void print_first_element(T& v)
{
	??? n = v.front();	// ???		// T�� �����̳��� Ÿ���̹Ƿ� ???�� T�� ġȯ �Ұ���
	cout << n << endl;
}
*/

/*
// ����
template <typename T>
void print_first_element(T& v)
{
	typename T::value_type n = v.front();
	// - typename�� �Ϲ�ȭ �� ���ø��� Ÿ���� ����� �� ���.
	// - typedef [type] value_type �� "����"
	cout << n << endl;
}
*/

// C++11 �ذ�å - �����Ϸ��� front()�� ����Ÿ���� �� �� �ִ�. (auto)
template <typename T>
void print_first_element(T& v)
{
	auto n = v.front();
	cout << n << endl;
}


int main()
{
	vector<int> v(10, 3);		// 10���� 3���� �ʱ�ȭ
	print_first_element(v);

	vector<double> v2(10, 3);	// 10���� 3���� �ʱ�ȭ
	list<double> l1(10, 3);
}

// template ��� �����̳ʴ� �ڽ��� �����ϴ� Ÿ���� �ֽ��ϴ�.
// �׷��� �� Ÿ���� �ܺο��� �˰� ���� ���� �ֽ��ϴ�.
// ���� print_first_element()
// �׷��� �Ʒ�ó�� ��������ϴ�.

/*
template<typename T> class list
{
public:
	typedef T value_type;
	//......
};

//list<int> s;
list<int>::value_type n;	// n�� �ᱹ int Ÿ��
*/
