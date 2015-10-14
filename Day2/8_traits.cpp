// 8. Traits - 95page

#include <iostream>
using namespace std;

// print variable
template<typename T> void printv(T v)
{
	if (T is Pointer)	// TODO
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int n = 10;
	double d = 3.3;

	printv(n);
	printv(d);

	printv(&n);
}