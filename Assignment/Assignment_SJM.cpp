/**
[C++ 심화 최종 과제]

- 작성자: 심재민
*/

#include <iostream>
#include "Assignment_SJM.h"

int main()
{
	// 1.
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "[Assignment 01]" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	DoAssignment<Assignment01>(true);
	std::cout << std::endl;

	// 2.
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "[Assignment 02]" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	DoAssignment<Assignment02>(true);
	std::cout << std::endl;

	// 3.
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "[Assignment 03]" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	DoAssignment<Assignment03>(true);
	std::cout << std::endl;
}
