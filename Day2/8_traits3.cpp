// 8. Traits3 - 96page

#include <iostream>
using namespace std;

template <typename T> struct IsPointer
{
	enum { value = false };
};

template <typename T> struct IsPointer<T*>
{
	enum { value = true };
};

template <typename T> struct IsArray
{
	enum { value = false };
	enum { size = -1 };
};

template <typename T, int N> struct IsArray<T[N]>
{
	enum { value = true };
	enum { size = N };
};

template <typename T> void foo(const T& a)
{
	if (IsArray<T>::value)
		cout << "Is an array. Size is " << IsArray<T>::size << endl;
	else
		cout << "Is not an array" << endl;
}

int main()
{
	int x[10] = { 0 };
	foo(x);
}
