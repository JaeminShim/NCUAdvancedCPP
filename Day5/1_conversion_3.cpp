// 1. ��ȯ_3 - 44page
// ��ȯ�� �����

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// [Pattern] RAII (Resource Acquisition Is Initialize)
//				   ������/�Ҹ��ڷ� �ڿ��� �������ڴ� �ǹ��� C++ Idioms
class OFile
{
	FILE* file;

public:
	//OFile(const char* name, const char* mode = "wt")
	//{
	//	file = fopen(name, mode);
	//}

	// C.
	// ��ȯ �����ڴ� ������ ��찡 ����.
	// explicit ������: ���ڰ� �� ���� �����ڰ� �Ͻ��� ��ȯ�� ����Ű�� ���� ���´�.
	// - ���� �� �� ¥�� �����ڴ� explicit�� �ٿ����� �����ϴ°� �⺻ convension��
	explicit OFile(const char* name, const char* mode = "wt")
	{
		file = fopen(name, mode);
	}


	~OFile()
	{
		fclose(file);
	}

	// OFile -> FILE*���� ��ȯ�� ����Ѵ�.
	operator FILE*() { return file; }
};

//// A.
//int main()
//{
//	OFile f("a.txt");
//
//	// ������ �ִ� C �Լ���� ���� �۾�
//	fputs("hello", f);		// OFile -> FILE* ��ȯ �ȴٸ� ��� �����ϴ�.
//
//	fprintf(f, "%d", 10);
//
//
//	// in MFC
//	// CWnd		=> HWND
//	// CDC		=> HDC
//	// CFONT	=> HFONT
//}

// B.
void foo(OFile f) {}

int main()
{
	OFile f("a.txt");

	foo(f);			// OK : �翬��

	foo("hello");	// OK : ??? �� ������ ���� ������?
					//		const char* => OFile �Ͻ��� ��ȯ�� �߻��ϱ� ����
					// => ������ �� ����
}
