1~3번 문제를 풀어서 제출해 주세요.. 
수료 기준은 한문제만 제출하셔도 됩니다.
어렵지 않으니 잘 생각해서 작성해 보세요..

//-------------------------------------------------------------------
1. int x[10] = { 1,3,5,7,9,2,4,6,8,10 }; 의 배열을 STL 의 sort()함수를 사용해서 정렬한후 출력해 보세요

   A. 내림 차순의 비교 정책을 담은 일반 함수를 사용해서 정렬하세요
   B.  ""                        함수 객체를 사용해서 정렬하세요
   C.  ""                        람다를 사용해서 정렬하세요


//-------------------------------------------------------------------
2. 인자로 전달된 T 타입에서 포인터를 제거한 타입 을 구하는 remove_pointer<> traits를 만들어보세요..

#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T> void foo(T a)
{
	typename my_remove_pointer<T>::type n; 

	cout << typeid(n).name() << endl;  // int 가 나와야 합니다.
}
int main()
{
	int n = 10;
	foo(&n);
}


//-------------------------------------------------------------------
3. 아래의 간단한 People 클래스에 대해서 생성자, 소멸자, 깊은 복사로 구현한 복사생성자, 대입연산자, move 생성자, move 대입연산자를 구현해 보세요..
   
class People
{
	char* name;
	int age;
public:
};


참고

1. 제출 기한 : 11월 21일(토) 24 : 00 까지
2. 메일 : smkang @ ioacademy.co.kr 로 보내 주시면 됩니다.
3. 수료 기준은 1~3번 문제중 하나이상만 제출하시면 됩니다... 간단하게 만들어서 보내 주세요
4. 이름을 적지 않고 보내 주시는 분이 가끔 계십니다.꼭, 파일명을 이름으로 해서 보내 주세요..
