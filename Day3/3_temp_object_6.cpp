// 3. �ӽð�ü - 36 page~
// template�� ���� ����ȭ

#include <iostream>
using namespace std;

//template <typename T>
//class stack
//{
//public:
//	// [A]
//	//void push(T a) {};
//	//T pop() {};
//
//	// [B]
//	// T�� ū ����ü�� �� �ִ�. => ����ȭ
//	// 1. call by value ��� const T&
//	void push(const T& a) {};
//
//	// 2. pop()�� ���ſ� ������ ���ÿ� �ϸ� ����ȭ�� �Ұ��� (�ӽð�ü�� ����ؾ� ��)
//	//T& pop() {};
//
//	// ���ſ� ������ �и��Ǿ�� �Ѵ�.
//	void pop() {}	// ���Ÿ�
//	T& top() {}		// ���ϸ�, �������� �ʴ´�.
//};

// [C]
#include <stack>
// STL �����̳��� ��� �Լ��� ���ſ� ������ ���ÿ� �ϴ� �Լ��� �����ϴ�.
// 1. �ӽ� ��ü�� �����ؼ� ���� ����ȭ
// 2. ���� �������� ������ ������ ����

int main()
{
	stack<int> s;
	s.push(10);
	cout << s.top() << endl;
}