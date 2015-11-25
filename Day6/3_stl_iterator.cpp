// 3. STL 반복자 - 175 page

#include <iostream>
using namespace std;

template <typename T, typename U> T xfind(T first, T last, U value)
{
	while (first != last && *first != value)
		++first;
	// return first == last ? 0 : first;	// 0은 T의 값으로 사용하기 어려워 짐
	return first;
}

template<typename T> struct Node
{
	T data;
	Node* next;
	Node(T a, Node* n) : data(a), next(n) {}
};

// slist 안에 있는 Node를 가리키는, 스마트 포인터와 유사한, 객체를 만듭니다.
template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	// xfind로 보내려면 ++, *, ==, != 의 4가지 연산이 가능해야 합니다.
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

	// 모든 컨테이너 설계자는 자신의 반복자 이름을 약속된 형태로 외부에 알려야 한다.
	typedef slist_iterator<T> iterator;

	void push_front(const T& a) { head = new Node<T>(a, head); }

	// 모든 컨테이너 설계자는 반드시 자신의 시작과 끝 다음을 가리키는
	// 반복자 객체를 리턴하는 함수를 제공하기로 약속한다.
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

	slist<int>::iterator p = s.begin();	// 이제 p는 포인터처럼 생각하면 됩니다.
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}

	slist<int>::iterator p2 = xfind(s.begin(), s.end(), 20);
	cout << *p2 << endl;
}
