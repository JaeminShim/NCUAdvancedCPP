// 4. �ݺ��� �з� - 181page

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
	list<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	// 20�� ã�� �ʹ�.
	// - JAVA style : s.find(20);
	// - STL  style : find(s.begin(), s.end(), 20);

	sort(s.begin(), s.end());	// ERROR!
}