/**
[C++ ��ȭ ���� ����]

- �ۼ���: �����

- �ڸ�Ʈ:
	�����ϰ� ����� �����޶�� �޽����� �����ϱ� ������ �ó׿� -_-;
	�ڵ� �б� �����ϰ� ���� �˼��մϴ� �Ф�
	�Ʒ� VERBOSITY_LEVEL�� ���� ���� ���� �� �մϴ�......
*/

#pragma once

#include <iostream>
#include <string>

#define VERBOSITY_LEVEL 1	// set 0 to get minimize output


//-------------------------------------------------------------------
// Declaration of helper functions
//-------------------------------------------------------------------
template <typename T, size_t N>
void			PrintArray(const T(&arr)[N]);
#if (VERBOSITY_LEVEL > 0)
std::string		GetCodeFormatted(const char* pCodeString);
#define _trace(_code)	\
	std::cout << "<Execute>:" << std::endl << "\"" << #_code << "\"" << std::endl	\
			  << "<Result> :" << std::endl;	\
	_code
#define _trace_formatted(_code)	\
	std::cout << "<Execute>:" << std::endl << "\"" << GetCodeFormatted(#_code).c_str() << "\"" << std::endl	\
			  << "<Result> :" << std::endl;	\
	_code
#else
#define _trace(_code) _code
#define _trace_formatted(_code) _code
#endif


//-------------------------------------------------------------------
// Assignment helper classes
//-------------------------------------------------------------------
class Assignment
{
public:
	void Run() { RunImpl(); }

protected:
	virtual void RunImpl() abstract;
};

template <typename T>
class DoAssignment
{
//private:
	DoAssignment() = delete;
	DoAssignment(const DoAssignment&) = delete;
public:
	explicit DoAssignment(bool bRunImmediately)
	{
		if (bRunImmediately)
			operator()();
	}

	inline void operator()()
	{
		_instance.Run();
	}

private:
	T _instance;
};


//-------------------------------------------------------------------
// Assignment 01
//-------------------------------------------------------------------
#include <algorithm>
/*
//-------------------------------------------------------------------
1. int x[10] = { 1,3,5,7,9,2,4,6,8,10 }; �� �迭�� STL �� sort()�Լ��� ����ؼ� �������� ����� ������

   A. ���� ������ �� ��å�� ���� �Ϲ� �Լ��� ����ؼ� �����ϼ���
   B.  ""                        �Լ� ��ü�� ����ؼ� �����ϼ���
   C.  ""                        ���ٸ� ����ؼ� �����ϼ���
*/
class Assignment01 : public Assignment
{
protected:
	virtual void RunImpl() override
	{
		std::cout << "A. ���� ������ �� ��å�� ���� �Ϲ� �Լ��� ����ؼ� �����ϼ���" << std::endl;
		_trace(SortWith(SortPredFuncDecr<int>););
		std::cout << std::endl;

		std::cout << "B. ���� ������ �� ��å�� ���� �Լ� ��ü�� ����ؼ� �����ϼ���" << std::endl;
		_trace(SortWith(SortPredFunctorDecr<int>()););
		std::cout << std::endl;

		std::cout << "C. ���� ������ �� ��å�� ���� ���ٸ� ����ؼ� �����ϼ���" << std::endl;
		_trace(SortWith([](int a, int b) { return a > b; }););
	}

	template <typename T>
	static bool SortPredFuncDecr(T a, T b)
	{
		return a > b;
	}

	template <typename T>
	struct SortPredFunctorDecr
	{
		inline bool operator()(T a, T b) const
		{
			return a > b;
		}
	};

	template <typename T>
	void SortWith(T pred)
	{
		int x[10];
		memcpy(x, _x, sizeof(x));	// initialize
		std::cout << "- before: "; PrintArray(x);
		std::sort(x, x + _countof(x), pred);
		std::cout << "- after : "; PrintArray(x);
	}

private:
	static const int _x[10];
};
const int Assignment01::_x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };


//-------------------------------------------------------------------
// Assignment 02
//-------------------------------------------------------------------
#pragma warning(push)
#pragma warning(disable:4101)
#include <typeinfo>
/*
//-------------------------------------------------------------------
2. ���ڷ� ���޵� T Ÿ�Կ��� �����͸� ������ Ÿ�� �� ���ϴ� remove_pointer<> traits�� ��������..

#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T> void foo(T a)
{
	typename my_remove_pointer<T>::type n; 

	cout << typeid(n).name() << endl;  // int �� ���;� �մϴ�.
}
int main()
{
	int n = 10;
	foo(&n);
}
*/
class Assignment02 : public Assignment
{
protected:
	virtual void RunImpl() override
	{
		int n = 10;
		foo(&n);
	}

	template<typename T>
	void foo(T a)
	{
		typename my_remove_pointer<T>::type n;	// warning C4101: 'n' : unreferenced local variable
		_trace(std::cout << typeid(n).name() << std::endl);
	}

	template<typename T> struct my_remove_pointer { };
	template<typename T> struct my_remove_pointer<T*> { typedef T type; };
};
#pragma warning(pop)


//-------------------------------------------------------------------
// Assignment 03
//-------------------------------------------------------------------
/*
//-------------------------------------------------------------------
3. �Ʒ��� ������ People Ŭ������ ���ؼ� ������, �Ҹ���, ���� ����� ������ ���������, ���Կ�����, move ������, move ���Կ����ڸ� ������ ������..
   
class People
{
	char* name;
	int age;
public:
};
*/
class Assignment03 : public Assignment
{
protected:
	virtual void RunImpl() override
	{
		_trace_formatted({ \
			People john("John", 20);					\
			People paul(std::move(People("paul", 30)));	\
			People john_copy(john);						\
			People paul_assign;							\
			People paul_assign_move("_temp", 10);		\
			paul_assign = paul;							\
			paul_assign_move = People("paul", 40);		\
		});
	}

	class People
	{
		char* name;
		int age;

	public:
		// A. default constructor
		People() : name(nullptr), age(0)
		{
#if (VERBOSITY_LEVEL > 0)
			std::cout << "A. constructor of " << this << "()" << std::endl;
#endif
		}

		// A. constructor
		People(const char* _name, int _age) : age(_age)
		{
#if (VERBOSITY_LEVEL > 0)
			std::cout << "A. constructor of " << this << " (" << _name << ", " << _age << ")" << std::endl;
#endif

			if (_name)
			{
				size_t size = sizeof(char) * strlen(_name) + 1;		// +1 for null-terminate character
				name = new char[size];
				memcpy_s(name, size, _name, size - 1);
				name[size - 1] = '\0';
			}
			else
			{
				name = nullptr;
			}
		}

		// B. destructor
		~People()
		{
#if (VERBOSITY_LEVEL > 0)
			std::cout << "B. destructor of " << this << std::endl;
#endif

			Release();
		}

		// C. copy constructor
		People(People& other) : age(other.age)
		{
#if (VERBOSITY_LEVEL > 0)
			std::cout << "C. copy constructor of " << this << " (" << &other << ")" << std::endl;
#endif

			if (other.name)
			{
				size_t size = sizeof(char) * strlen(other.name) + 1;		// +1 for null-terminate character
				name = new char[size];
				memcpy_s(name, size, other.name, size - 1);
				name[size - 1] = '\0';
			}
			else
			{
				name = nullptr;
			}
		}

		// D. move constructor
		People(People&& other)
		{
#if (VERBOSITY_LEVEL > 0)
			std::cout << "D. move constructor of " << this << " (" << &other << ")" << std::endl;
#endif

			name = other.name;
			age = other.age;

			other.name = nullptr;
			other.age = 0;
		}

		// E. assign operator
		People& operator=(People& other)
		{
#if (VERBOSITY_LEVEL > 0)
			std::cout << "E. assign operator of " << this << " (" << &other << ")" << std::endl;
#endif

			Release();

			if (other.name)
			{
				size_t size = sizeof(char*) * strlen(other.name) + 1;	// +1 for null-terminate character
				name = new char[size];
				memcpy_s(name, size, other.name, size - 1);
				name[size - 1] = '\0';
			}

			age = other.age;

			return *this;
		}

		// F. move assign operator
		People& operator=(People&& other)
		{
#if (VERBOSITY_LEVEL > 0)
			std::cout << "F. move assign operator of " << this << " (" << &other << ")" << std::endl;
#endif

			if (this != &other)
			{
				Release();

				name = other.name;
				age = other.age;

				other.name = nullptr;
				other.age = 0;
			}
			return *this;
		}

	private:
		void Release()
		{
			if (nullptr != name)
			{
				delete[] name;
				name = nullptr;
			}
			age = 0;
		}
	};
};


//-------------------------------------------------------------------
// Definition of helper functions
//-------------------------------------------------------------------

template <typename T, size_t N>
void PrintArray(const T(&arr)[N])
{
	bool bPrintDelim = false;
	for (T item : arr)
	{
		if (bPrintDelim)
			std::cout << ", ";
		else
			bPrintDelim = true;
		std::cout << item;
	}
	std::cout << std::endl;
}

#if (VERBOSITY_LEVEL > 0)
std::string GetCodeFormatted(const char* pCodeString)
{
	std::string result;
	result.reserve(strlen(pCodeString));
	const char* p = pCodeString;
	int nDepth = 0;
	bool bBOL = true;

	auto NewLine = [&]()
	{
		result += '\n';
		bBOL = true;
	};
	auto WriteChar = [&](char c)
	{
		if (bBOL)
		{
			for (int i = 0; i < nDepth; ++i)
				result += "    ";
			bBOL = false;
		}
		result += c;
	};

	char ch;
	while ('\0' != (ch = *p++))
	{
		switch (ch)
		{
		case ';':
			WriteChar(ch);
			NewLine();
			break;
		case '{':
			WriteChar(ch);
			NewLine();
			++nDepth;
			break;
		case '}':
			--nDepth;
			WriteChar(ch);
			break;
		case ' ':
		case '\t':
			if (!bBOL)
				WriteChar(ch);
			break;
		default:
			WriteChar(ch);
			break;
		}
	}
	return result;
}
#endif