// 3_�Լ���ü_3 (17page)

#include <algorithm>	// STL���� �̹� ��å ��ü�� ������ sort()�� �ֽ��ϴ�.
#include <iostream>


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


int main()
{
	int x[10] = { 2,4,6,8,10,1,3,5,7,9 };

	// STL�� sort() �Լ��� ���ø� �Լ� �Դϴ�.

	// 1. �� ��å���� �Ϲ��Լ��� ����� ��
	// ����: ��å�� ��ü�ص� sort()�� ����� �� �� �̴�. => �ڵ� �޸� ����
	// ����: ��å�� �ζ��� ġȯ�� �� ����. => ������
	std::sort(x, x + 10, cmp_incr);		// sort(int*, int*, bool(*)(int,int)) �Լ� ����
	std::sort(x, x + 10, cmp_decr);		// �� �Լ� ��� => �ڵ� �޸� ��뷮 �������� ����

	// 2. �� ��å���� �Լ� ��ü�� ����� ��
	// ����: ��å�� �ζ��� ġȯ�� �� �ִ�. => ������.
	// ����: ��å�� ��ü�� ȸ�� ��ŭ�� sort() ���� �ڵ� ����.
	Less f1;
	Greater f2;
	std::sort(x, x + 10, f1);			// sort(int*, int*, Less) �Լ� ����
	std::sort(x, x + 10, f2);			// sort(int*, int*, Greater) �Լ� ����
}
