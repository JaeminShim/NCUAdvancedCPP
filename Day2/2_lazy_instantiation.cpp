// 2. ������ �ν��Ͻ�ȭ

/*
class AAA
{
public:
	void foo(int a)
	{
		*a = 10;	// ERORR. int�� ������(*) �� �� ����.
	}
};
*/

// ������ �ν��Ͻ�ȭ (Lazy Instantiation)
// : template ���κ��� �Լ� ���� �� ���� ���� �Լ��� �����ȴ�.
template<typename T>
class AAA
{
public:
	void foo(T a)
	{
		*a = 10;
	}
};


int main()
{
	AAA<int> aaa;
	//aaa.foo(1);	// <- Lazy Instantiation
}
