// 1. ��ȯ 6

#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;			// 'a'�� �Է�

	//if (cin.fail())
	//	cout << "failed" << endl;

	if (cin)	// => cin.operator void*()�� ����ǰ� �ִ�. ��, void*���� ��ȯ!
		cout << "succeed" << endl;
				// ��?

	cout << n << endl;	// 1. 0  / 2. 10  / 3. 97  / 4. -1  ����?
}

namespace EXAMPLE
{
	void true_function() {}

	// cin�� istream�� ��ü�Դϴ�.
	class istream
	{
	public:
		bool fail() {}

		// 1.
		//operator bool() { return fail() ? false : true; }

		// 2.
		//operator void*() { return fail() ? 0 : this; }	// ���� cin ����

		// 3. 
		//typedef void(*F)();
		//operator F() { return fail() ? 0 : &true_function; }

		// 4.
	private:
		struct Dummy
		{
			void true_function() {}
		};
	public:
		typedef void(Dummy::*MF)();
		operator MF() { return fail() ? 0 : &Dummy::true_function; }
	};
	istream cin;

	// cin�� ��Į�� �׽�Ʈ �ϰ� �;����ϴ�. (if(...)�� ����)
	// 1. bool�� ��ȯ����. ... �׷��� ����ڰ� �Ʒ�ó�� ����ߴ�.
	cin << n;		// cin�� bool ��ȯ�Ǹ� ����Ʈ �������� ó���Ǿ ������ ���� �ʴ´�!

	// 2. if() ���� ���� �� �ִµ�, ����Ʈ ������ �Ұ����ؾ� �Ѵ�.
	//	  => void* �� ��ȯ
	// ��������� ���� cin

	// �׷���... �Ʒ� �ڵ尡 (������ Ÿ�ӿ�) ������ ���� �ʴ´�.
	delete cin;		// ������ Ÿ�� ������ �ƴ�! (��Ÿ�ӿ��� ����)

	// 3. delete �Ұ��� �� �����͸� ������� - �Լ�������!!
	//    �׷���... ����ڰ� �Ʒ��� ���� ����� �� �ִ�
	void(*f)() = cin;

	// 4. �����̺� ��� �Լ� �����͸� �������!
	//    ������ ������ boolean�̴�.
	//    => Safe Bool idiom	// 47page
	void(Dummy::*fm)() = cin;	// �Ұ���!
};