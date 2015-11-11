// 1. 변환_5 - 44page

#include <memory>
using namespace std;

int main()
{
	// C++ 표준 스마트포인터

	shared_ptr<int> p1(new int);

	shared_ptr<int> p2 = new int;	// ERROR : 생성자가 explicit

	// shared_ptr<>의 생성자는 explicit으로 선언 되었으므로 반드시 ()로 초기화 해야 합니다.
}