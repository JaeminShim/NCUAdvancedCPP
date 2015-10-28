// 3. 임시객체 - 35 page~

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	//Point p;	// 지역객체. 이름이 있고, scope를 벗어날 때 파괴

	cout << "AAA" << endl;
	Point();	// 임시객체 생성. 이름이 없고, 문장의 끝에서 파괴된다.
				// C++ 표준문서에 공식 언급된 기법.
				// 명칭: "unnamed object"
	cout << "BBB" << endl;
}