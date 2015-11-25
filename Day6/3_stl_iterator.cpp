// 3. STL �ݺ��� - 175 page

#include <iostream>
using namespace std;

template <typename T, typename U> T xfind(T first, T last, U value)
{
	while (first != last && *first != value)
		++first;
	// return first == last ? 0 : first;	// 0�� T�� ������ ����ϱ� ����� ��
	return first;
}

template<typename T> struct Node
{
	T data;
	Node* next;
	Node(T a, Node* n) : data(a), next(n) {}
};

// slist �ȿ� �ִ� Node�� ����Ű��, ����Ʈ �����Ϳ� ������, ��ü�� ����ϴ�.
template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	// xfind�� �������� ++, *, ==, != �� 4���� ������ �����ؾ� �մϴ�.
	inline slist_iterator& operator++() { current = current->next; return *this; }
	inline T& operator*() { return current->data; }
	inline bool operator==(const slist_iterator& it) { return it.current == current; }
	inline bool operator!=(const slist_iterator& it) { return it.current != current; }
};

template<typename T> class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}

	// ��� �����̳� �����ڴ� �ڽ��� �ݺ��� �̸��� ��ӵ� ���·� �ܺο� �˷��� �Ѵ�.
	typedef slist_iterator<T> iterator;

	void push_front(const T& a) { head = new Node<T>(a, head); }

	// ��� �����̳� �����ڴ� �ݵ�� �ڽ��� ���۰� �� ������ ����Ű��
	// �ݺ��� ��ü�� �����ϴ� �Լ��� �����ϱ�� ����Ѵ�.
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	slist<int>::iterator p = s.begin();	// ���� p�� ������ó�� �����ϸ� �˴ϴ�.
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}

	slist<int>::iterator p2 = xfind(s.begin(), s.end(), 20);
	cout << *p2 << endl;
}
