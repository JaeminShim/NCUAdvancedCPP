// 9. nullptr 2

void foo(int* p) {}

// Effective C++ å������ lockAndCall() �Լ��� ���� ��� ����
template<typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

int main()
{
	foo(0);					// OK

//	logTime(foo, 0);		// �Ǿ�� �ϴµ�, ERROR! Perfect forwarding�ε�!!!

	logTime(foo, nullptr);	// nullptr�� nullptr_t Ÿ���Դϴ�.
							// nullptr_t�� ��� Ÿ���� �����ͷ� �Ͻ��� ����ȯ �˴ϴ�.
}
