// <6> ����Լ� - 2 (65 page)
// ��� ��ü�� ��� �Լ��� ȣ���� �� �ִ�.
// ����� ���� �������� ���� ��� ��� �Լ��� �ݵ�� "��� �Լ��� �ؾ� �Ѵ�".
// �Լ� ���ڷ� const T&�� ��ü�� �޴� ��찡 ����. ��� �Լ��� ȣ���� �� �ְ� �ȴ�.

#include <iostream>

class Rect
{
	int x, y, w, h;
public:
	int GetArea() const
	{
		return w * h;
	}
};

// call by value ��� const T& �� ����.
void foo(const Rect& r)
{
	int n = r.GetArea();
}

int main()
{
	Rect r;					// �ʱ�ȭ �ߴٰ� �����ϰ�

	int n = r.GetArea();	// OK: �ƹ� ���� ����

	foo(r);
}