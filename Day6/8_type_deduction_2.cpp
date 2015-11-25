// 8. type deduction 2

int main()
{
	int x = 10;
	const int cx = x;
	const int& rx = cx;

	// A.
	auto n = rx;	// typeof(n) ???
	// auto�� type deduction�� template�� type deduction�� �����ϴ�.
	// => (typeof(n) == int)

	auto& r = rx;	// auto: const int	/ typeof(rx) == const int&

	// �� ���� Ȯ��
	//n = 10;		// OK	 : n�� int Ÿ��
	//r = 10;		// ERROR : r�� const int& Ÿ��

	// B.
	decltype(rx) d = cx;	// d�� ���� Ÿ���ϱ��? => rx�� ���� Ÿ��. �� const int&
}