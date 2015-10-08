// 3_�Լ���ü_4

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

// (�ζ��� �ɼ��� �������� ��)
// Q1. foo �Լ��� ���� �ڵ�� �� ��?
// > 3��
// Q2. foo ���� ���� �ڵ忡�� �� ���� �Լ��� ������?
// > 3��. main(), cmp_incr, cmp_decr
