#include<iostream>

// 7.�ζ����Լ�
// ��ũ���Լ��� ���� ���ϰ� ����ϱ����� �Լ�

// 1) ��ũ�� �Լ�
#define SQUARE(x) ((x)*(x))		// ��ũ���Լ� (�ƿ� ��ü�ϴ°� ��, ��ó���� �����̴� = ��ó���Ⱑ ��ÿ���)

// 2) �ζ��� �Լ�
inline int SQUARE_inline(int x)
{
	return x * x;
}

int main(void)
{
	std::cout << "------------ < 1) ��ũ�� �Լ�  > ----------------" << std::endl;
	// 1) ��ũ�� �Լ�
	std::cout << SQUARE(5) << std::endl; // == std::cout << ((5)*(5)) << std::endl;

	// * ��°�� *
	// 25

	std::cout << "------------ < 2) �ζ��� �Լ�  > ----------------" << std::endl;
	// 2) �ζ����Լ�
	// �ζ����Լ��� �����Ϸ��� �켱 ó���ؼ� �ſ� ���� �ӵ��� ����� ó���� �����ϴ�
	// �� ���ǵ��� �ſ� �����ϰ� �׿����� Ȱ���� �������̴�.

	std::cout << SQUARE_inline(5) << std::endl; // == std::cout << (5*5) << std::endl;
	std::cout << SQUARE_inline(12) << std::endl; // == std::cout << (12*12) << std::endl;

	// * ��°�� *
	// 25
	// 144

	return 0;
}
