// 4. �ݺ��� �з� 4 - 181page
// "�������� ����"

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

// B.
// STL�� advance() �����
//template<typename T> void xadvance(T& p, int n)	// n�� ����� ���� �����غ���
//{
//	//// 1) ���� ���� �ݺ��ڸ� ��� ����
//	//p = p + n;
//
//	// 2) ��� �ݺ��� ��� ����
//	while (--n)
//		++p;
//}

// C.
// STL�� 5���� �ݺ��� �з��� Ÿ��ȭ �մϴ�. empty class�� ���� �Ǿ� �ֽ��ϴ�.
/* // �̹� ������
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};
*/

// <����> empty class
// �ƹ� ����� ������ �������� Ÿ��.
// ��� ������
// 1) �Լ� �����ε��� ���
// 2) ���ø� ���� (���п� Ÿ��)

// D.
// ���� �ݺ��� ���� ��
/* // �̹� ������
template<typename T> class vector_iterator
{
public:
	// �ݺ����� ������ iterator_category��� �̸����� �˷��ݴϴ�.
	typedef random_access_iterator_tag iterator_category;
};
template<typename T> class list_iterator
{
public:
	// �ݺ����� ������ iterator_category��� �̸����� �˷��ݴϴ�.
	typedef bidirectional_iterator_tag iterator_category;
};
*/

// E.
// STL�� advance() ����� (2)
template<typename T> void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	// ���� ���� �ݺ��ڸ� ��� ����
	p = p + n;
}
template<typename T> void xadvance_imp(T& p, int n, input_iterator_tag)
{
	// ��� �ݺ��� ��� ����
	while (--n) ++p;
}

/* // F. T�� primitive Ÿ���� �������� ���, iterator_category�� �����Ƿ� ���� �߻���.

template<typename T> void xadvance(T& p, int n)	// n�� ����� ���� �����غ���
{
	xadvance_imp(p, n, typename T::iterator_category());
}
*/

// G.
// �ݺ����� ����
// 1) ��¥ ������
// 2) ����� Ÿ������ ���� �ݺ���
//  �� 2���� ������ ������ �Ϲ�ȭ �Լ��� ����Ⱑ ��ƽ��ϴ�.
//  �Ʒ� ������ ����մϴ�.
/* // �̹� ������
template <typename T> struct iterator_traits
{
	typedef typename T::iterator_category iterator_category;
};

// �������϶��� ���� �κ�����ȭ
template <typename T> struct iterator_traits<T*>	// 94�⵵ ó�� ���� => is_pointer�� ���
{
	typedef random_access_iterator_tag iterator_category;
};
*/

// "�������� ����": �ذ� �Ұ��� �� ���̴� ������ �߰� ���̾ �߰������ν� �ذ��� �� �ִٴ� ����
template<typename T> void xadvance(T& p, int n)	// n�� ����� ���� �����غ���
{
	xadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
}


int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	vector<int> v(x, x + 10);

	vector<int>::iterator p = v.begin();

	// A.
	//advance(p, 5);	// p�� 5ĭ �����ϴ� �Լ�

	// B.
	xadvance(p, 5);		// ���� ����

	// F.
	int* p2 = x;
	xadvance(p2, 5);	// ERROR: int*::iterator_category ����. ��¥ �����͵� �ݺ��� �Դϴ�!

	cout << *p << endl;
}
