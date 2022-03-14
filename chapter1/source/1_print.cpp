#include <iostream>

// 1. 출력(std::cout << 출력대상)

int main(void)
{
	int num = 20;
	std::cout << "Hello World!" << std::endl;		// = [Hello World!\n]
	std::cout << "Hello" << "World!" << std::endl;	// = [HelloWorld!\n]
	std::cout << num << ' ' << 'A';					// = [20 A]
	std::cout << ' ' << 3.14 << std::endl;			// = [ 3.14\n]

	// * 출력결과 *
	// Hello World!
	// HelloWorld!
	// 20 A 3.14

	// std::cout<< '출력대상';
	// std::cout<<'출력대상1'<<'출력대상2'<<'출력대상3';
	return 0;
}