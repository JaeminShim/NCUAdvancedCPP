// <6> ����Լ� - 3 (appendix)
// ��ü�� ������� ����� ��� �Լ� - ��κ��� ���¼ҽ��� ����ϴ� ���

#include <vector>
#include <iostream>

class Car
{
	volatile mutable int mCount;

public:
	Car() : mCount(0) {}

	void AddRef() const { ++mCount; }
	void Release() const { if (--mCount == 0) delete this; }
};

std::vector<Car*> v;

int main()
{
	Car* p = new Car;
	//v.push_back(p);
	//// �� �̻� p�� �ʿ� ����. ������ �ɱ�? => �ȵ� => ������� ��� ����
	//delete p;

	Car* p1 = new Car;
	p1->AddRef();	// p1�� ��ü�� ����Ű�Ƿ� ���� ��� ����
	Car* p2 = p1;
	p2->AddRef();	// �����͸� �������ָ� ���� ��� ����

	const Car* p3 = p2;
	p3->AddRef();	// AddRef()�� ��� �Լ����� ��
	p3->Release();	// Release()�� ��� �Լ����� ��

	p2->Release();
	p1->Release();
}
