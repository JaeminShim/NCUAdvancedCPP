// 3. Ŭ���� ���ø� - 79page

 template <typename T>
 class stack
 {
	 T* buff;

 public:
	 // ���� �� �����ڷ� �´� ����?

	 stack()	{}	// 1. O
	 stack<T>()	{}	// 2. X - �Ϻ� �����Ϸ��� ���

	 // ���� �����ڷ� �´� ����?
	 stack(const stack&	s1) {}		// 1. . - 2���� ������ ���ø� ���({ }) �ȿ����� �� ǥ���� ���.
	 stack(const stack<T>& s1) {}	// 2. O

	 // 1) ��� �Լ��� �ܺ� ����
	 void push(T a);

	 // 2) Ŭ���� ���ø��� ��� �Լ� ���ø� (80page)
	 template<typename U> T foo(U a);
 };

 // 1) Ŭ���� ���ø��� ��� �Լ��� �ܺ� ����
 template<typename T>
 void stack<T>::push(T a)
 {
 }

 // 2) Ŭ���� ���ø��� ��� �Լ� ���ø� (80page)
 //template<typename T, U>	// X - �� ���ÿ� �����ؾ� ��
 template<typename T> template<typename U>
 T stack<T>::foo(U a)
 {

 }

 int main()
 {
	 //stack s1;	// ERROR - stack�� Ÿ��(Ŭ����)�� �ƴ϶� Ʋ(template)�̴�
	 stack<int> s2;	// OK	 - stack<T>�� Ÿ���̴�.
 }