#include <iostream>

// 1. ���(std::cout << ��´��)

int main(void)
{
	int num = 20;
	std::cout << "Hello World!" << std::endl;		// = [Hello World!\n]
	std::cout << "Hello" << "World!" << std::endl;	// = [HelloWorld!\n]
	std::cout << num << ' ' << 'A';					// = [20 A]
	std::cout << ' ' << 3.14 << std::endl;			// = [ 3.14\n]

	// * ��°�� *
	// Hello World!
	// HelloWorld!
	// 20 A 3.14

	// std::cout<< '��´��';
	// std::cout<<'��´��1'<<'��´��2'<<'��´��3';
	return 0;
}