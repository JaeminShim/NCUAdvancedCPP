// 3_함수객체_4

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

inline bool cmp_incr(int a, int b) { return a < b; }

inline bool cmp_decr(int a, int b) { return a > b; }

template<typename T> void foo(T f)
{
	f(1, 2);
}


int main()
{
	Less f1;
	Greater f2;

	foo(cmp_incr);
	foo(cmp_decr);
	foo(f1);
	foo(f2);
}

// (인라인 옵션을 적용했을 때)
// Q1. foo 함수의 기계어 코드는 몇 개?
// > 3개
// Q2. foo 빼고 기계어 코드에는 몇 개의 함수가 있을까?
// > 3개. main(), cmp_incr, cmp_decr
