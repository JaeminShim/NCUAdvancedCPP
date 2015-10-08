// <4> 람다 - 8 (24page)
// 

#include <iostream>

class Test
{
	int data = 0;

public:
	void foo()	// == void foo(Test* test)
	{
		//auto f = [this]() { std::cout << data << std::endl; };
		//auto f = [=]() { std::cout << data << std::endl; };

		// [과제] - 다음 람다의 closure object를 예상해보자!
		// - 캡쳐한 변수는 this.
		// - 따라서 원본의 값이 변하게 됨
		//int data = 10;
		auto f = [=]() { data = 20; };
		f();

		////------------------------------------------------------
		//class ClosureObject
		//{
		//private:
		//	Test* _this;

		//public:
		//	ClosureObject(Test* obj): _this(obj) {}

		//	inline void operator()() const
		//	{
		//		(*_this).data = 0;
		//	}
		//};
		//auto _f = ClosureObject(this);
		////------------------------------------------------------

		/**
		7	The lambda-expression’s compound-statement yields the function-body (8.4) of the function call operator,
			but for purposes of name lookup (3.4), determining the type and value of this (9.3.2) and transforming idexpressions
			referring to non-static class members into class member access expressions using (*this) (9.3.1),
			the compound-statement is considered in the context of the lambda-expression.
				[Example:
					struct S1 {
						int x, y;
						int operator()(int);
						void f() {
							[=]()->int {
								return operator()(this->x + y); // equivalent to S1::operator()(this->x + (*this).y)
								// this has type S1*
							};
						}
					};
				? end example ]
			Further, a variable __func__ is implicitly defined at the beginning of the compoundstatement
			of the lambda-expression, with semantics as described in 8.4.1.
		*/
	}
};

int main()
{
	Test t;
	t.foo();
}