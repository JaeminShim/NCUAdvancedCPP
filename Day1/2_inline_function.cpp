// 2_인라인함수 (14page ~ )

// 개념: 진짜 호출이 아닌 기계어 코드의 치환
// 장점: 빠르다.
// 단점: 대개 여러번 치환되면 목적코드(실행파일)의 크기가 커진다.
//		1~2줄의 작은 함수는 목적코드를 줄이기도 합니다.

// "cl [filename] /FAs"
// - 인라인 치환 옵션: /Ob1
		int Add1(int a, int b) { return a + b; }
inline	int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);
	int n2 = Add2(1, 2);
}