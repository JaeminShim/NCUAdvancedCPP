// 3. Tuple

#include <iostream>
using namespace std;

template<typename ... Types> class xtuple
{
};

int main()
{
	xtuple<int, double, char> t3;// (1, 2.2, 'A');
}