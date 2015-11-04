// 2. Variadic template - C++11/14 이야기 - 112 page 5번
// 가변인자 꺼내기 - 핵심!

#include <iostream>
using namespace std;

// A. 1번째 인자는 이름 있는 일반 변수로 받아야 한다.
//    모두 가변인자로 받으면 꺼낼 수 없다.
// B. 나머지 값을 꺼내기 위해 재귀 호출 사용.
// C. 종료를 위해 인자가 없는 함수를 만든다.
template<typename T, typename ... Types> void foo(T value, Types ... args)
{
	static int n = 0;	// 재귀 여부를 확인하기 위한 스태틱 카운터

	//참고> typeid : C++의 RTTI
	cout << "(" << ++n << ") " << typeid(T).name() << " : " << value << endl;

	// Call recursively // 실제로 재귀 호출이 아님에 유의할 것!!! 실제로 전부 다른 함수를 호출한다.
	foo(args...);	// (1st) foo(2, 3, 4);	=> 2	|	3, 4
					// (2nd) foo(3, 4);		=> 3	|	4
					// (3rd) foo(4);		=> 4	|
					// (4th) foo( );
}

// 재귀의 종료를 위해서 인자가 없는 함수
void foo()
{
	cout << "end of foo" << endl;
}

int main()
{
	foo(1, 2, 3, 4);
}