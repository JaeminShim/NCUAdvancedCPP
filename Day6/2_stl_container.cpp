// 2. STL �����̳� - 175 page

#include <iostream>
using namespace std;

// list�� ������ ���ô�.
template<typename T> struct Node
{
	T data;
	Node* next;
	Node(T a, Node* n) : data(a), next(n) {}
};

template<typename T> class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}
	// �̱� ����Ʈ�� �տ� �߰��ϴ� �ڵ�� �Ʒ�ó�� �����ڸ� �� Ȱ���ϸ� �˴ϴ�.
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);	// �޸� �׸� ���� (175page)
}
