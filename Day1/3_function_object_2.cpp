// 3_함수객체_2 (17page)

// !!!IMPORTANT!!!
// 1. 일반 함수는 자신만의 타입이 없다. signature(리턴타입과 인자타입의 모양)가 동일한 모든 함수는 같은 타입이다.
// 2. 함수 객체는 자신만의 타입이 있다. signature(리턴타입과 인자타입의 모양)가 동일하더라도 모든 함수 객체는 다른 타입이다.

#include <algorithm>

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

Less	f1;
Greater	f2;

//--------------------------------------------------
// 성능 저하 없이 정책 변경이 가능한 Sort() 만들기
// 템플릿과 함수 객체를 사용한 기술!!!
template<typename T>
void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(x[i], x[j]))
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[10] = { 2,4,6,8,10,1,3,5,7,9 };
	Sort(x, 10, f1);	// Sort(int*, int, Less) 함수 생성
	Sort(x, 10, f2);	// Sort(int*, int, Greater) 함수 생성
}
