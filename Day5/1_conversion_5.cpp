// 1. ��ȯ_5 - 44page

#include <memory>
using namespace std;

int main()
{
	// C++ ǥ�� ����Ʈ������

	shared_ptr<int> p1(new int);

	shared_ptr<int> p2 = new int;	// ERROR : �����ڰ� explicit

	// shared_ptr<>�� �����ڴ� explicit���� ���� �Ǿ����Ƿ� �ݵ�� ()�� �ʱ�ȭ �ؾ� �մϴ�.
}