// 9. nullptr 2

void foo(int* p) {}

// Effective C++ 책에서는 lockAndCall() 함수로 예를 들어 설명
template<typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

int main()
{
	foo(0);					// OK

//	logTime(foo, 0);		// 되어야 하는데, ERROR! Perfect forwarding인데!!!

	logTime(foo, nullptr);	// nullptr은 nullptr_t 타입입니다.
							// nullptr_t는 모든 타입의 포인터로 암시적 형변환 됩니다.
}
