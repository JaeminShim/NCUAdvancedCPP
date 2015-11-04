// 2. Variadic template - C++11/14 �̾߱� - 112 page 5��
// �������� ������ - �ٽ�!

#include <iostream>
using namespace std;

// A. 1��° ���ڴ� �̸� �ִ� �Ϲ� ������ �޾ƾ� �Ѵ�.
//    ��� �������ڷ� ������ ���� �� ����.
// B. ������ ���� ������ ���� ��� ȣ�� ���.
// C. ���Ḧ ���� ���ڰ� ���� �Լ��� �����.
template<typename T, typename ... Types> void foo(T value, Types ... args)
{
	static int n = 0;	// ��� ���θ� Ȯ���ϱ� ���� ����ƽ ī����

	//����> typeid : C++�� RTTI
	cout << "(" << ++n << ") " << typeid(T).name() << " : " << value << endl;

	// Call recursively // ������ ��� ȣ���� �ƴԿ� ������ ��!!! ������ ���� �ٸ� �Լ��� ȣ���Ѵ�.
	foo(args...);	// (1st) foo(2, 3, 4);	=> 2	|	3, 4
					// (2nd) foo(3, 4);		=> 3	|	4
					// (3rd) foo(4);		=> 4	|
					// (4th) foo( );
}

// ����� ���Ḧ ���ؼ� ���ڰ� ���� �Լ�
void foo()
{
	cout << "end of foo" << endl;
}

int main()
{
	foo(1, 2, 3, 4);
}