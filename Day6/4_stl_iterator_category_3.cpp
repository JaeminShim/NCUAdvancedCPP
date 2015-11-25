// 4. �ݺ��� �з� 3 - 181page

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

// �ݺ����� �з�
// 1. �Է� �ݺ��� Input iterator				: =*p, ++
// 2. ��� �ݺ��� Ouput iterator				: *p=, ++
// 3. ������ �ݺ��� forward iterator			: �����, ++					<�̱۸���Ʈ �ݺ���>
// 4. ����� �ݺ��� bidirectional iterator	: �����, ++, --				<������Ʈ �ݺ���>
// 5. ���� ���� �ݺ��� random access iterator	: �����, ++, --, +, -, []	<���ӵ� �޸�>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10, };
	int* p = find(x, x + 10, 5);	// 1, 2��° ���ڴ� �ݺ��� �Դϴ�.
									// �ּ� �䱸������ 5���� �з��߿� �����ϱ��?
									// => �Է� �ݺ��� (�б⸸)

	reverse(x, x + 10);				// => ����� �ݺ���
	sort(x, x + 10);				// => ���� ���� �ݺ��� (divide and conquer)

	//-----------------------------------------------------------------------
	//slist<int> s2;
	//reverse(s2.begin(), s2.end());	// ERROR

	list<int> s;
	//sort(s.begin(), s.end());	// ERROR: ���� ���� �ݺ��ڰ� �ʿ�, list�� �ݺ��ڴ� ������̴�.
	s.sort();					// OK: Quick sort�� �ƴ� �ٸ� �˰���!

	vector<int> v;
	//v.sort();					// ERROR: �� ��� �Լ��� ����. ������ ������ ����;;;

	//find();		// _InIt	: input iterator
	//reverse();	// _BidIt	: bidirectional iterator
	//sort();		// _RanIt	: random access iterator
}