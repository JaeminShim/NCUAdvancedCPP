// 4. 반복자 분류 2 - 181page

// 반복자의 분류
// 1. 입력 반복자 Input iterator		(컨테이너 -> 프로그램)
//   : =*p, ++
// 2. 출력 반복자 Ouput iterator		(프로그램 -> 컨테이너)
//   : *p=, ++
// 3. 전진형 반복자 forward iterator
//   : 입출력, ++,					<싱글리스트 반복자>
// 4. 양방향 반복자 bidirectional iterator
//   : 입출력, ++, --,				<더블리스트 반복자>
// 5. 임의 접근 반복자 random access iterator
//   : 입출력, ++, --, +, -, []		<연속된 메모리>

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main()
{
	// 우리가 만든 slist를 생각해 봅시다.
	slist<int> s;

	s.push_front(10);
	s.push_front(20);

	slist<int>::iterator p = s.begin();
	++p;	// OK
	--p;	// ERROR - 연산자 없음. => 만들 수 있을까? => 자료구조 특성 상 불가능
}