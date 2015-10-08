// <4> 람다 - 7 (24page ~)
// 지역변수 캡쳐

#include <iostream>

int main()
{
	int v1 = 10, v2 = 20;

	//auto f1 = [=](int a) { v1 = a; };			// ERROR: operator()는 const 함수!
	auto f2 = [=](int a) mutable { v1 = a; };	// OK: mutable 람다 - v1, v2를 mutable로 선언
	auto f3 = [&](int a) { v1 = a; };			// reference 캡쳐

	f2(20);
	std::cout << v1 << std::endl;

	//--------------------------------------------------------
	//class Closure_Object_Non_Mutable
	//{
	//public:
	//	Closure_Object_Non_Mutable(int a, int b) : v1(a), v2(b) {}
	//	inline void operator()(int a) const		// 상수함수!
	//	{
	//		v1 = a;								// ERROR
	//	}
	//
	//private:
	//	int v1;
	//	int v2;
	//};
	//auto f1 = Closure_Object_Non_Mutable();
	//--------------------------------------------------------
	class Closure_Object_Mutable
	{
	public:
		Closure_Object_Mutable(int a, int b) : v1(a), v2(b) {}
		inline void operator()(int a) const		// 상수함수!
		{
			v1 = a;
		}

	private:
		// 상수 함수에서도 변경 가능하게 해달라
		mutable int v1;
		mutable int v2;
	};
	auto _f2 = Closure_Object_Mutable(v1, v2);
	//--------------------------------------------------------
	class Closure_Object_Reference
	{
	public:
		Closure_Object_Reference(int& a, int& b) : v1(a), v2(b) {}
		inline void operator()(int a) const		// 상수함수!
		{
			v1 = a;
		}

	private:
		int& v1;
		int& v2;
	};
	auto _f3 = Closure_Object_Reference(v1, v2);
	//--------------------------------------------------------
}