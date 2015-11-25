// 4. �ݺ��� �з� 2 - 181page

// �ݺ����� �з�
// 1. �Է� �ݺ��� Input iterator		(�����̳� -> ���α׷�)
//   : =*p, ++
// 2. ��� �ݺ��� Ouput iterator		(���α׷� -> �����̳�)
//   : *p=, ++
// 3. ������ �ݺ��� forward iterator
//   : �����, ++,					<�̱۸���Ʈ �ݺ���>
// 4. ����� �ݺ��� bidirectional iterator
//   : �����, ++, --,				<������Ʈ �ݺ���>
// 5. ���� ���� �ݺ��� random access iterator
//   : �����, ++, --, +, -, []		<���ӵ� �޸�>

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main()
{
	// �츮�� ���� slist�� ������ ���ô�.
	slist<int> s;

	s.push_front(10);
	s.push_front(20);

	slist<int>::iterator p = s.begin();
	++p;	// OK
	--p;	// ERROR - ������ ����. => ���� �� ������? => �ڷᱸ�� Ư�� �� �Ұ���
}