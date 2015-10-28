// 3. 임시객체 - 36 page~
// template과 성능 최적화

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
//	// T는 큰 구조체일 수 있다. => 최적화
//	// 1. call by value 대신 const T&
//	void push(const T& a) {};
//
//	// 2. pop()이 제거와 리턴을 동시에 하면 최적화가 불가능 (임시객체를 사용해야 함)
//	//T& pop() {};
//
//	// 제거와 리턴은 분리되어야 한다.
//	void pop() {}	// 제거만
//	T& top() {}		// 리턴만, 제거하지 않는다.
//};

// [C]
#include <stack>
// STL 컨테이너의 멤버 함수는 제거와 리턴을 동시에 하는 함수가 없습니다.
// 1. 임시 객체를 제거해서 성능 최적화
// 2. 예외 안전성의 강력한 보장을 위해

int main()
{
	stack<int> s;
	s.push(10);
	cout << s.top() << endl;
}