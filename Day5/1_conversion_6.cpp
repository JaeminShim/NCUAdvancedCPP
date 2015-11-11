// 1. 변환 6

#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;			// 'a'를 입력

	//if (cin.fail())
	//	cout << "failed" << endl;

	if (cin)	// => cin.operator void*()가 수행되고 있다. 즉, void*로의 변환!
		cout << "succeed" << endl;
				// 왜?

	cout << n << endl;	// 1. 0  / 2. 10  / 3. 97  / 4. -1  답은?
}

namespace EXAMPLE
{
	void true_function() {}

	// cin은 istream의 객체입니다.
	class istream
	{
	public:
		bool fail() {}

		// 1.
		//operator bool() { return fail() ? false : true; }

		// 2.
		//operator void*() { return fail() ? 0 : this; }	// 현재 cin 버전

		// 3. 
		//typedef void(*F)();
		//operator F() { return fail() ? 0 : &true_function; }

		// 4.
	private:
		struct Dummy
		{
			void true_function() {}
		};
	public:
		typedef void(Dummy::*MF)();
		operator MF() { return fail() ? 0 : &Dummy::true_function; }
	};
	istream cin;

	// cin을 스칼라 테스트 하고 싶었습니다. (if(...)로 조사)
	// 1. bool로 변환하자. ... 그런데 사용자가 아래처럼 사용했다.
	cin << n;		// cin이 bool 변환되면 쉬프트 연산으로 처리되어서 에러가 나지 않는다!

	// 2. if() 문에 넣을 수 있는데, 쉬프트 연산은 불가능해야 한다.
	//	  => void* 로 변환
	// 여기까지가 현재 cin

	// 그런데... 아래 코드가 (컴파일 타임에) 에러가 나지 않는다.
	delete cin;		// 컴파일 타임 에러는 아님! (런타임에서 에러)

	// 3. delete 불가능 한 포인터를 사용하자 - 함수포인터!!
	//    그런데... 사용자가 아래와 같이 사용할 수 있다
	void(*f)() = cin;

	// 4. 프라이빗 멤버 함수 포인터를 사용하자!
	//    안전한 형태의 boolean이다.
	//    => Safe Bool idiom	// 47page
	void(Dummy::*fm)() = cin;	// 불가능!
};