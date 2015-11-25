// 9. nullptr

#include <iostream>
using namespace std;

void foo(void* p) { cout << "void*" << endl; }	// 1
void foo(int   n) { cout << "int"   << endl; }	// 2
void goo(char* p) { cout << "char*" << endl; }

int main()
{
	// A.
	foo(0);			// 2
	foo((void*)0);	// 1

	// 0�� ����(int)�Դϴ�. �����ͷ� �Ͻ��� ����ȯ �����մϴ�. (�����Ϸ� Ưȭ�� Ư�� ��Ģ)

	// B.
/*
#ifdef __cplusplus
	#define NULL 0
#else
	#define NULL (void*)0	// C++������ �Ͻ��� ����ȯ(T*)�� �Ұ����Ͽ� ����
#endif
*/

	foo(NULL);		// int. �� ����
	goo(NULL);		// ERROR: ������ C������ OK (�Ͻ��� ����ȯ : char* => void*)

	foo(nullptr);	// ������ 0�� ��Ÿ����. ��� Ÿ���� �����ͷ� �Ͻ��� ��ȯ�ȴ�.
	goo(nullptr);
}