// 2_�ζ����Լ� (14page ~ )

// ����: ��¥ ȣ���� �ƴ� ���� �ڵ��� ġȯ
// ����: ������.
// ����: �밳 ������ ġȯ�Ǹ� �����ڵ�(��������)�� ũ�Ⱑ Ŀ����.
//		1~2���� ���� �Լ��� �����ڵ带 ���̱⵵ �մϴ�.

// "cl [filename] /FAs"
// - �ζ��� ġȯ �ɼ�: /Ob1
		int Add1(int a, int b) { return a + b; }
inline	int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);
	int n2 = Add2(1, 2);
}