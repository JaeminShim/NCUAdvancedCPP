// 2. Trivial - 156 page
// �� trivial�� ����ؾ� �ϴ°�?

// cafe.naver.com/cppmaster�� ���� ���� �Խù����� 'ŰĹ' �˻�, �ٿ�ε�.
// (�ȵ���̵� ŶĹ �ڵ� ��)
// kitkat/core/core/include/utils/typehelpers.h

#include <iostream>
using namespace std;

// [B]
// strcpy�� template ���� (��ü�� shallow copy)
//template <typename T>
//void copy_type(T* dst, T* src, size_t sz)
//{
//	memcpy(dst, src, sizeof(T) * sz);
//}

// [C]
#include <type_traits>	// C++ ǥ���� traits
template <typename T>
inline void copy_type(T* dst, T* src, size_t sz)
{
	if (is_trivially_copyable<T>::value)	// compile-time�� ����, �� �� code�� ����
	{
		cout << "trivial �� ���� ������. memcpy ���" << endl;
		memcpy(dst, src, sizeof(T) * sz);
	}
	else 
	{
		cout << "���� �����ڰ� �ϴ� ���� �ִ�. ���� �����ڷ� ����" << endl;
		while (sz--)
		{
			//new(dst) T;		// ������ ȣ��
			new(dst) T(*src);	// ���� ������ ȣ��
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