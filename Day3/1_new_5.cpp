// 1. new - 28 page

#include <iostream>
#include <vector>
using namespace std;

// vector�� �޸� ���� ����� ������ ȣ�� �̾߱�

int main()
{
	// [A]
	vector<int> v(10, 3);	// 10���� 3���� �ʱ�ȭ

	v.resize(7);			// 7���� �ٿ��޶�

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(1);			// ���� element �� �� �߰�

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.shrink_to_fit();		// �ʿ� ���� ��� ����

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	// [B]
	class DBConnect {
	public:
		// �����ڿ��� DB�� ����
		// �Ҹ��ڿ��� ���� ����
	};

	//vector<DBConnect> v2(10);

	//v2.resize(7);	// �پ�� 3���� ��ü�� �޸𸮿� ��� �ִ�.
	//				// ������ �Ҹ��ڸ� ��������� ȣ���ؼ� DB�� �ݾƾ� �Ѵ�.

	//v2.resize(8);	// �þ 1���� ��ü�� ���� �޸𸮴� �����Ѵ�.
	//				// ������ �����ڸ� ��������� ȣ���ؼ� DB�� �����ؾ� �Ѵ�.
	//				// �������� ����� ȣ���� �ݵ�� �ʿ��ϴ�.

	// [etc]
	class Test {
	public:
		Test(int value) { cout << "Constructor" << endl; }
		~Test() { cout << "Destructor" << endl; }
	};
	Test* pDBCon = static_cast<Test*>(operator new(sizeof(Test)));
	new (&pDBCon) Test(0xFFFFFFFF);
	delete(pDBCon);
}