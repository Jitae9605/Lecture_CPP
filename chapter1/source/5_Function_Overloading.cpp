#include <iostream>

// 5.�Լ������ε�
// c++�� ������ �Լ����̾ �Ű����� ���� �� �ڷ��� ���� ���� �����Ͽ� �ٸ� ������ �����ϰԲ� ����Ѵ�(c�� ���X)
// ��, ���� �̸��� �Լ��� �������ϼ� �ִ�

// 1) �Լ�
int MyFunc(int num)
{
	num++;
	return num;

}

int MyFunc(int a, int b)
{
	return a + b;
}

// 2)�Լ�
void MyFunc_2(void)
{
	std::cout << "MyFunc_2(void) called" << std::endl;
}

void MyFunc_2(char c)
{
	std::cout << "MyFunc_2(char c) called" << std::endl;
}

void MyFunc_2(int a, int b)
{
	std::cout << "MyFunc_2(int a, int b) called" << std::endl;
}

int main(void)
{
	std::cout << "------------ < 1) ���� > ----------------" << std::endl;
	// 1) ����
	std::cout << MyFunc(20) <<std::endl;		// MyFunc(int num)
	std::cout << MyFunc(30, 40) << std::endl;		// MyFunc(int a, int b)

	// * ��°�� *
	// 21
	// 70
	
	std::cout << "------------ < 2) �⺻ > ----------------" << std::endl;
	// 2)�⺻
	MyFunc_2();
	MyFunc_2('A');
	MyFunc_2(12, 13);

	// * ��°�� *
	// MyFunc_2(void) called
	// MyFunc_2(char c) called
	// MyFunc_2(int a, int b) called
	


	return 0 ;
}