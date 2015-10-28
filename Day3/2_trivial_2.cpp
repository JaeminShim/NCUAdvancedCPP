// 2. Trivial - 156 page
// 왜 trivial을 고려해야 하는가?

// cafe.naver.com/cppmaster의 예전 수업 게시물에서 '키캣' 검색, 다운로드.
// (안드로이드 킷캣 코드 중)
// kitkat/core/core/include/utils/typehelpers.h

#include <iostream>
using namespace std;

// [B]
// strcpy의 template 버전 (객체의 shallow copy)
//template <typename T>
//void copy_type(T* dst, T* src, size_t sz)
//{
//	memcpy(dst, src, sizeof(T) * sz);
//}

// [C]
#include <type_traits>	// C++ 표준의 traits
template <typename T>
inline void copy_type(T* dst, T* src, size_t sz)
{
	if (is_trivially_copyable<T>::value)	// compile-time에 결정, 한 쪽 code만 생성
	{
		cout << "trivial 한 복사 생성자. memcpy 사용" << endl;
		memcpy(dst, src, sizeof(T) * sz);
	}
	else 
	{
		cout << "복사 생성자가 하는 일이 있다. 복사 생성자로 복사" << endl;
		while (sz--)
		{
			//new(dst) T;		// 생성자 호출
			new(dst) T(*src);	// 복사 생성자 호출
			++dst; ++src;
		}
	}
	memcpy(dst, src, sizeof(T) * sz);
}

int main()
{
	// [A]
	char s1[10] = "hello";
	char s2[10] = "";

	//strcpy(s2, s1);

	// [B]
	copy_type(s2, s1, 10);
}