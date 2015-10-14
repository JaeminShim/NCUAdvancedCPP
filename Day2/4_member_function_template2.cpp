// 4. ��� �Լ� ���ø� 2

#include <memory>

using namespace std;

class Animal {};
class Dog : public Animal {};

int main()
{
	Dog* pDog = new Dog;
	Animal* p = pDog;		// OK - �θ� �����ʹ� �ڽ� ��ü�� ����ų �� �ִ�.

	// ����Ʈ ������
	shared_ptr<Dog> p3(new Dog);
	shared_ptr<Animal> p4 = p3;		// OK - shared_ptr�� �Ϲ�ȭ �� ���� �����ڰ� ����!

	// ��� ����Ʈ �����ʹ� ���������, ���Կ�����, �񱳿�����(==, !=) �Լ���
	// generic �������� �����ؾ� �Ѵ�. (83page)
}