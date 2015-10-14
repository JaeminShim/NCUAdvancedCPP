// 2. 지연된 인스턴스화

/*
class AAA
{
public:
	void foo(int a)
	{
		*a = 10;	// ERORR. int는 역참조(*) 할 수 없다.
	}
};
*/

// 지연된 인스턴스화 (Lazy Instantiation)
// : template 으로부터 함수 생성 시 실제 사용된 함수만 생성된다.
template<typename T>
class AAA
{
public:
	void foo(T a)
	{
		*a = 10;
	}
};


int main()
{
	AAA<int> aaa;
	//aaa.foo(1);	// <- Lazy Instantiation
}
