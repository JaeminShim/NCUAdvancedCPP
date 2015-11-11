// 1. 변환_4 - 44page

// explicit 생성자를 사용한 클래스는
// 초기화 시에 대입연산자(=)를 사용할 수 없고 직접 호출()해야 한다.
class Test
{
	int value;
public:
	explicit Test(int n) : value(n) {}
};

int main()
{
	// 아래 두 줄의 차이점
	Test t1(5);		// 1. 인자가 한 개인 생성자 호출
	Test t2 = 5;	// 2. A. 5를 변환 생성자를 사용해서 Test 임시객체 생성
					//    B. 임시객체를 복사 생성자를 사용하여 t2에 복사
					//       (변환생성자 -> 복사생성자)
}