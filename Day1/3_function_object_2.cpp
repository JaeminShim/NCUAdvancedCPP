// 3_�Լ���ü_2 (17page)

// !!!IMPORTANT!!!
// 1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� ����. signature(����Ÿ�԰� ����Ÿ���� ���)�� ������ ��� �Լ��� ���� Ÿ���̴�.
// 2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�. signature(����Ÿ�԰� ����Ÿ���� ���)�� �����ϴ��� ��� �Լ� ��ü�� �ٸ� Ÿ���̴�.

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
// ���� ���� ���� ��å ������ ������ Sort() �����
// ���ø��� �Լ� ��ü�� ����� ���!!!
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
	Sort(x, 10, f1);	// Sort(int*, int, Less) �Լ� ����
	Sort(x, 10, f2);	// Sort(int*, int, Greater) �Լ� ����
}
