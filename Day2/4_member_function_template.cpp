// 4. ��� �Լ� ���ø� - 81page

// 1. complex�� T�� ����� ���� - double�̸� �� �� ������ double�� int ���� �����ϴ�.
// 2. T a = T() : zero initialize
//    T�� ǥ�� Ÿ���̰ų� �������̸� 0���� �ʱ�ȭ
//    T�� ����� Ÿ���̸� Ƽ��Ʈ �����ڷ� �ʱ�ȭ.
template<typename T>
class complex
{
	T re;
	T im;

public:
	complex(T a = T(), T b = T()) : re(a), im(b) {}	// zero initialize

	//// ���� ������
	//complex(const complex<T>& c);

	// �Ϲ�ȭ �� ��������� (82page)
	// "U�� T�� ����(����)�� �� �ִٸ� complex<U>�� complex<T>�� ����(����)�� �� �־�� �Ѵ�. (82page)"
	// - Effective C++ 3rd Ed.
	template<typename U>
	complex(const complex<U>& c);

	// ��� complex ������ private�� ������ �� �־�� �Ѵ�.
	template<typename>	// typename�� ������ ������� �����Ƿ� �̸��� ������ �� �ʿ�� ����.
	friend class complex;
};

// generic ���� �������� �ܺ� ����
template<typename T>
template<typename U>
complex<T>::complex(const complex<U>& c): re(c.re), im(c.im)	// Ÿ Ÿ���� private ����� ����!
{
}


int main()
{
	complex<int> c1(1, 3);		// OK

	complex<int> c2 = c1;		// ? => ���� ������(OK to create implicitly)

	complex<double> c3 = c1;	// ? => ���� ������(FAILED to create implicitly)
}