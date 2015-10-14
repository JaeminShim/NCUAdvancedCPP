// 4. 멤버 함수 템플릿 2

#include <memory>

using namespace std;

class Animal {};
class Dog : public Animal {};

int main()
{
	Dog* pDog = new Dog;
	Animal* p = pDog;		// OK - 부모 포인터는 자식 객체를 가리킬 수 있다.

	// 스마트 포인터
	shared_ptr<Dog> p3(new Dog);
	shared_ptr<Animal> p4 = p3;		// OK - shared_ptr의 일반화 된 복사 생성자가 존재!

	// 모든 스마트 포인터는 복사생성자, 대입연산자, 비교연산자(==, !=) 함수가
	// generic 버전으로 존재해야 한다. (83page)
}