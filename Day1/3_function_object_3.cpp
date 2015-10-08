// 3_함수객체_3 (17page)

#include <algorithm>	// STL에는 이미 정책 교체가 가능한 sort()가 있습니다.
#include <iostream>


struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

inline bool cmp_incr(int a, int b) { return a < b; }

inline bool cmp_decr(int a, int b) { return a > b; }


int main()
{
	int x[10] = { 2,4,6,8,10,1,3,5,7,9 };

	// STL의 sort() 함수는 템플릿 함수 입니다.

	// 1. 비교 정책으로 일반함수를 사용할 때
	// 장점: 정책을 교체해도 sort()의 기계어는 한 개 이다. => 코드 메모리 감소
	// 단점: 정책이 인라인 치환될 수 없다. => 느리다
	std::sort(x, x + 10, cmp_incr);		// sort(int*, int*, bool(*)(int,int)) 함수 생성
	std::sort(x, x + 10, cmp_decr);		// 위 함수 사용 => 코드 메모리 사용량 증가하지 않음

	// 2. 비교 정책으로 함수 객체를 사용할 때
	// 장점: 정책이 인라인 치환될 수 있다. => 빠르다.
	// 단점: 정책을 교체한 회수 만큼의 sort() 기계어 코드 생성.
	Less f1;
	Greater f2;
	std::sort(x, x + 10, f1);			// sort(int*, int*, Less) 함수 생성
	std::sort(x, x + 10, f2);			// sort(int*, int*, Greater) 함수 생성
}
