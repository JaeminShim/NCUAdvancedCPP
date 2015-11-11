// 1. 변환_3 - 44page
// 변환의 장단점

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// [Pattern] RAII (Resource Acquisition Is Initialize)
//				   생성자/소멸자로 자원을 관리하자는 의미의 C++ Idioms
class OFile
{
	FILE* file;

public:
	//OFile(const char* name, const char* mode = "wt")
	//{
	//	file = fopen(name, mode);
	//}

	// C.
	// 변환 생성자는 위험한 경우가 많다.
	// explicit 생성자: 인자가 한 개인 생성자가 암시적 변환을 일으키는 것을 막는다.
	// - 인자 한 개 짜리 생성자는 explicit을 붙여놓고 제작하는게 기본 convension임
	explicit OFile(const char* name, const char* mode = "wt")
	{
		file = fopen(name, mode);
	}


	~OFile()
	{
		fclose(file);
	}

	// OFile -> FILE*로의 변환을 허용한다.
	operator FILE*() { return file; }
};

//// A.
//int main()
//{
//	OFile f("a.txt");
//
//	// 기존에 있던 C 함수들로 파일 작업
//	fputs("hello", f);		// OFile -> FILE* 변환 된다면 사용 가능하다.
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

	foo(f);			// OK : 당연함

	foo("hello");	// OK : ??? 왜 에러가 나지 않을까?
					//		const char* => OFile 암시적 변환이 발생하기 때문
					// => 위험할 수 있음
}
