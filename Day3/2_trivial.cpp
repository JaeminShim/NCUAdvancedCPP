// 2. Trivial - 156 page
// (참고: Inside C++ object 책 - 1996년 출간)

#include <iostream>
using namespace std;

// trivial (자명한) 생성자 : 아무 일도 하지 않는 생성자

// trivial한 생성자의 조건
// 1. 가상 함수가 없고
// 2. 부모가 없거나 부모의 생성자가 trivial 하고
// 3. 객채형 멤버가 없거나 객체형 멤버의 생성자가 trivial하고
// 4. 사용자가 만든 생성자가 없을 때

class A 
{
};

// [D]
//class B

class B : public A
{
public:
	virtual void foo() {}

	// [B]
	//virtual void foo() {}

	// [C]
	//A a;
};

int main()
{
	// [A] B의 생성자는 trivial 할까요?
	B* p = static_cast<B*>(malloc(sizeof(B)));
	//p->foo();	// ERROR

	new (p) B;	// 생성자 호출 -> vtable 생성
	p->foo();	// OK

	// [B] 부모 생성자 호출 필요하면 non-trivial
	// [C] 멤버 생성자 호출 필요하면 non-trivial
	// [D] 생성자 필요코드 없으면 trivial
}