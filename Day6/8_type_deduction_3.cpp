// 8. type deduction 3

int main()
{
	int n = 10;
	int* p = &n;

	// A.
	decltype(n)  n2;	// typeof(n2) == int
	//decltype(*p) n3;	// typeof(n3) == int&
						// <= *p = 10 ���� ǥ���� �����ϴ�. ���� * �����ڴ� ���������Ѵ�.

	// B.
	const int cx = n;
	const int& rx = cx;

	auto a1 = rx;			// typeof(a1) == int
	decltype(rx) a2 = rx;	// typeof(a2) == const int&			// C++11
	decltype(auto) a3 = rx;	// �캯�� Ÿ������ a3�� ����µ�,
							// �߷� ��Ģ�� decltype() ��Ģ����...	// C++14

	// <= (decltype(rx) a2 = rx; => rx�� �ߺ��ؼ� ����. decltype�� param ��� auto ���)
}