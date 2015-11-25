// 8. type deduction 2

int main()
{
	int x = 10;
	const int cx = x;
	const int& rx = cx;

	// A.
	auto n = rx;	// typeof(n) ???
	// auto의 type deduction은 template의 type deduction과 동일하다.
	// => (typeof(n) == int)

	auto& r = rx;	// auto: const int	/ typeof(rx) == const int&

	// 위 내용 확인
	//n = 10;		// OK	 : n은 int 타입
	//r = 10;		// ERROR : r은 const int& 타입

	// B.
	decltype(rx) d = cx;	// d는 무슨 타입일까요? => rx와 동일 타입. 즉 const int&
}