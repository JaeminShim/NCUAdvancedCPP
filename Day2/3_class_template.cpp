// 3. 클래스 템플릿 - 79page

 template <typename T>
 class stack
 {
	 T* buff;

 public:
	 // 다음 중 생성자로 맞는 것은?

	 stack()	{}	// 1. O
	 stack<T>()	{}	// 2. X - 일부 컴파일러는 허용

	 // 복사 생성자로 맞는 것은?
	 stack(const stack&	s1) {}		// 1. . - 2번이 맞지만 템플릿 블록({ }) 안에서는 이 표현도 허용.
	 stack(const stack<T>& s1) {}	// 2. O

	 // 1) 멤버 함수의 외부 구현
	 void push(T a);

	 // 2) 클래스 템플릿의 멤버 함수 템플릿 (80page)
	 template<typename U> T foo(U a);
 };

 // 1) 클래스 템플릿의 멤버 함수의 외부 구현
 template<typename T>
 void stack<T>::push(T a)
 {
 }

 // 2) 클래스 템플릿의 멤버 함수 템플릿 (80page)
 //template<typename T, U>	// X - 둘 동시에 선언해야 함
 template<typename T> template<typename U>
 T stack<T>::foo(U a)
 {

 }

 int main()
 {
	 //stack s1;	// ERROR - stack은 타입(클래스)이 아니라 틀(template)이다
	 stack<int> s2;	// OK	 - stack<T>는 타입이다.
 }