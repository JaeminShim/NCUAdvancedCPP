// 3. 임시객체 - 35 page~

// 임시객체의 시작: 컴파일러가 연산의 과정에서 임시로 할당하게 되는 메모리 (레지스터)
int main()
{
	int a = 1, b = 2, c = 3;
	int s = 0;
	s = a * (b + c);
	
	// 위 expr을 컴파일 했을 때를 생각해 봅시다.
	// temp = b + c;
	// s = a * temp;

	// reg b
	// add c
	// mul a
}
