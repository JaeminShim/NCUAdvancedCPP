// 5. Typename

class AAA
{
public:
	//......
	//static int DWORD;	// 1)
	typedef int DWORD;	// 2)
};

int p = 0;

// ���ø�(T)�� �������� Ÿ���� ���� ������ �ݵ�� typename�� �տ� ����� �Ѵ�.

template <typename T>
typename T::DWORD foo(T a)
{
	// �Ʒ� �� ���� �ؼ��� ������
	// 1) DWORD�� static ��������ε� p(��������)�� �����ϰ� �ִ�. [!!!ǥ�� C++�� �⺻ ����!!!]
	// 2) DWORD�� T�ȿ� �ִ� typedef�� Ÿ���̴�. ������ ���� p�� �����ϰ� �ִ�.
	T::DWORD* p;			// ERROR - ǥ�� C++ (VC�� ���� ������)
	typename T::DWORD* p;	// OK - 2)���� ���� �����ϰ� ��	[!!!typename�� ź�� ���!!!]
	return 0;
}

int main()
{
	AAA aaa;
	foo(aaa);
}