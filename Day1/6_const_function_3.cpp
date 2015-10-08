// <6> 상수함수 - 3 (appendix)
// 객체의 수명관리 기술과 상수 함수 - 대부분의 오픈소스가 사용하는 기술

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
	//// 더 이상 p가 필요 없다. 지워도 될까? => 안됨 => 참조계수 기반 관리
	//delete p;

	Car* p1 = new Car;
	p1->AddRef();	// p1이 객체를 가르키므로 참조 계수 증가
	Car* p2 = p1;
	p2->AddRef();	// 포인터를 복사해주면 참조 계수 증가

	const Car* p3 = p2;
	p3->AddRef();	// AddRef()는 상수 함수여야 함
	p3->Release();	// Release()는 상수 함수여야 함

	p2->Release();
	p1->Release();
}
