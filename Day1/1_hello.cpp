#include <iostream>
#include <complex>
#include <chrono>

using namespace std;

int main()
{
	//---------------------------------------
	// 2진수
	int n1 = 0b10;	// expr for binary value
	cout << n1 << endl;

	//---------------------------------------
	// 자릿수 구분자
	int n2 = 1'000'000'000;
	cout << n2 << endl;

	//---------------------------------------
	// float
	float k = 3.4f;

	//---------------------------------------
	complex<int> c = 3i;
	cout << c << endl;

	//---------------------------------------
	auto m1 = 1min;

	//---------------------------------------
	double a = 10;
	auto a2 = a;

	//---------------------------------------
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++)
		cout << x[i];
	cout << endl;

	for (auto xv : x)	// ranged for. java, C#의 foreach()
		cout << xv;
	cout << endl;
}
