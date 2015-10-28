// 1. new - 28 page

#include <iostream>
#include <vector>
using namespace std;

// vector의 메모리 관리 기술과 생성자 호출 이야기

int main()
{
	// [A]
	vector<int> v(10, 3);	// 10개를 3으로 초기화

	v.resize(7);			// 7개로 줄여달라

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(1);			// 끝에 element 한 개 추가

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.shrink_to_fit();		// 필요 없는 요소 제거

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	// [B]
	class DBConnect {
	public:
		// 생성자에서 DB에 접속
		// 소멸자에서 접속 종료
	};

	//vector<DBConnect> v2(10);

	//v2.resize(7);	// 줄어든 3개의 객체는 메모리에 계속 있다.
	//				// 하지만 소멸자를 명시적으로 호출해서 DB를 닫아야 한다.

	//v2.resize(8);	// 늘어난 1개의 객체를 위한 메모리는 존재한다.
	//				// 하지만 생성자를 명시적으로 호출해서 DB에 접속해야 한다.
	//				// 생성자의 명시적 호출은 반드시 필요하다.

	// [etc]
	class Test {
	public:
		Test(int value) { cout << "Constructor" << endl; }
		~Test() { cout << "Destructor" << endl; }
	};
	Test* pDBCon = static_cast<Test*>(operator new(sizeof(Test)));
	new (&pDBCon) Test(0xFFFFFFFF);
	delete(pDBCon);
}