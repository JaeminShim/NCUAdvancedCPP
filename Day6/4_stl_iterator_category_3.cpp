// 4. 반복자 분류 3 - 181page

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

// 반복자의 분류
// 1. 입력 반복자 Input iterator				: =*p, ++
// 2. 출력 반복자 Ouput iterator				: *p=, ++
// 3. 전진형 반복자 forward iterator			: 입출력, ++					<싱글리스트 반복자>
// 4. 양방향 반복자 bidirectional iterator	: 입출력, ++, --				<더블리스트 반복자>
// 5. 임의 접근 반복자 random access iterator	: 입출력, ++, --, +, -, []	<연속된 메모리>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10, };
	int* p = find(x, x + 10, 5);	// 1, 2번째 인자는 반복자 입니다.
									// 최소 요구조건은 5가지 분류중에 무엇일까요?
									// => 입력 반복자 (읽기만)

	reverse(x, x + 10);				// => 양방향 반복자
	sort(x, x + 10);				// => 임의 접근 반복자 (divide and conquer)

	//-----------------------------------------------------------------------
	//slist<int> s2;
	//reverse(s2.begin(), s2.end());	// ERROR

	list<int> s;
	//sort(s.begin(), s.end());	// ERROR: 임의 접근 반복자가 필요, list의 반복자는 양방향이다.
	s.sort();					// OK: Quick sort가 아닌 다른 알고리즘!

	vector<int> v;
	//v.sort();					// ERROR: 이 멤버 함수는 없다. 제공할 이유가 없음;;;

	//find();		// _InIt	: input iterator
	//reverse();	// _BidIt	: bidirectional iterator
	//sort();		// _RanIt	: random access iterator
}