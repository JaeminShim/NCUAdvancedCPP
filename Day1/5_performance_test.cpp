// <5> 성능측정

#include <iostream>
#include <algorithm>
#include <functional>
#include "logTime.h"

using namespace std;

inline bool cmp1(int a, int b) { return a < b; }

inline bool cmp2(int a, int b) { return a > b; }

void test1(int cnt)
{
	int x[10000] = { 1,3,5,7,9,2,4,6,8,10 };
	for (int i = 0; i < cnt; ++i)
	{
		sort(x, x + 10000, cmp1);
		sort(x, x + 10000, cmp2);
	}
}

void test2(int cnt)
{
	int x[10000] = { 1,3,5,7,9,2,4,6,8,10 };
	for (int i = 0; i < cnt; ++i)
	{
		sort(x, x + 10000, less<int>());
		sort(x, x + 10000, greater<int>());
	}
}

void test3(int cnt)
{
	int x[10000] = { 1,3,5,7,9,2,4,6,8,10 };
	for (int i = 0; i < cnt; ++i)
	{
		sort(x, x + 10000, [](int a, int b) { return a > b; });
		sort(x, x + 10000, [](int a, int b) { return a < b; });
	}
}

int main()
{
	logTime(test1, 100);
	logTime(test2, 100);
	logTime(test3, 100);
}
