// 2. STL 컨테이너 - 175 page

#include <iostream>
using namespace std;

// list를 생각해 봅시다.
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
	// 싱글 리스트의 앞에 추가하는 코드는 아래처럼 생성자만 잘 활용하면 됩니다.
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);	// 메모리 그림 참고 (175page)
}
