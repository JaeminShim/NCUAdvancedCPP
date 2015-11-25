// 4. 반복자 분류 4 - 181page
// "간접층의 원리"

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

// B.
// STL의 advance() 만들기
//template<typename T> void xadvance(T& p, int n)	// n이 양수일 때만 생각해보자
//{
//	//// 1) 임의 접근 반복자만 사용 가능
//	//p = p + n;
//
//	// 2) 모든 반복자 사용 가능
//	while (--n)
//		++p;
//}

// C.
// STL은 5개의 반복자 분류를 타입화 합니다. empty class로 설계 되어 있습니다.
/* // 이미 존재함
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};
*/

// <참고> empty class
// 아무 멤버도 없으나 독립적인 타입.
// 사용 목적은
// 1) 함수 오버로딩에 사용
// 2) 템플릿 인자 (구분용 타입)

// D.
// 실제 반복자 만들 때
/* // 이미 존재함
template<typename T> class vector_iterator
{
public:
	// 반복자의 종류를 iterator_category라는 이름으로 알려줍니다.
	typedef random_access_iterator_tag iterator_category;
};
template<typename T> class list_iterator
{
public:
	// 반복자의 종류를 iterator_category라는 이름으로 알려줍니다.
	typedef bidirectional_iterator_tag iterator_category;
};
*/

// E.
// STL의 advance() 만들기 (2)
template<typename T> void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	// 임의 접근 반복자만 사용 가능
	p = p + n;
}
template<typename T> void xadvance_imp(T& p, int n, input_iterator_tag)
{
	// 모든 반복자 사용 가능
	while (--n) ++p;
}

/* // F. T가 primitive 타입의 포인터인 경우, iterator_category가 없으므로 에러 발생함.

template<typename T> void xadvance(T& p, int n)	// n이 양수일 때만 생각해보자
{
	xadvance_imp(p, n, typename T::iterator_category());
}
*/

// G.
// 반복자의 종류
// 1) 진짜 포인터
// 2) 사용자 타입으로 만든 반복자
//  위 2개의 차이점 때문에 일반화 함수를 만들기가 어렵습니다.
//  아래 도구를 사용합니다.
/* // 이미 존재함
template <typename T> struct iterator_traits
{
	typedef typename T::iterator_category iterator_category;
};

// 포인터일때를 위한 부분전문화
template <typename T> struct iterator_traits<T*>	// 94년도 처음 등장 => is_pointer의 기반
{
	typedef random_access_iterator_tag iterator_category;
};
*/

// "간접층의 원리": 해결 불가능 해 보이는 문제를 중간 레이어를 추가함으로써 해결할 수 있다는 원리
template<typename T> void xadvance(T& p, int n)	// n이 양수일 때만 생각해보자
{
	xadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
}


int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	vector<int> v(x, x + 10);

	vector<int>::iterator p = v.begin();

	// A.
	//advance(p, 5);	// p를 5칸 전진하는 함수

	// B.
	xadvance(p, 5);		// 구현 버전

	// F.
	int* p2 = x;
	xadvance(p2, 5);	// ERROR: int*::iterator_category 없음. 진짜 포인터도 반복자 입니다!

	cout << *p << endl;
}
