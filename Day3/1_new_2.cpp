// 1. new - 28 page

#include <iostream>
using namespace std;

// new�� ���������� �޸� �Ҵ��� �� ����ϴ� operator new()�� ������ �� �� �ֽ��ϴ�.
// (new keyword�� ������ �ϴ� ���� �ƴ�!!!)
// ��, �޸� �Ҵ� ����� ����.

void* operator new(size_t sz)
{
	cout << "my new: " << sz << endl;
	void* p = malloc(sz);
	return p;
}

// operator new() overloading
void* operator new(size_t sz, char* s, int n)
{
	cout << "my new2: " << sz << endl;
	void* p = malloc(sz);
	return p;
}

void operator delete(void* p)
{
	cout << "my delete" << endl;
	free(p);
}

int main()
{
	// calls new(sizeof(int))
	int* p = new int;
	delete p;

	// ���ڰ� 2�� �̻� �ִ� operator new()�� ����ϴ� ��
	int* p2 = new("AA", 2) int;
	delete p2;
}