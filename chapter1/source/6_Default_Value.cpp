#include <iostream>

//6. �Լ��� �Ű������� ����Ʈ�� ����
// C++�� �Լ��� �Ű������� ����Ʈ���� �����Ҽ� �ִ�.
// (�Լ�ȣ��� ���ڸ� �������� ������ �ڵ� �Էµ� ��)
// ����Ʈ���� ����κп��� ǥ���ص� �ȴ�

// 1) �Լ�
int Adder(int num1 = 1, int num2 = 2);		// ���𿡼� �Ű����� ����Ʈ���� ����

// 2)�Լ�
int BoxVolume(int length, int width = 1, int height = 1);

int main(void)
{
	std::cout << "------------ < 1) ����Ʈ�� ����  > ----------------" << std::endl;
	// 1) ����Ʈ�� ���� 
	std::cout << Adder() << std::endl;		// �Լ��� �Ű����� ���� -> ����Ʈ���� �Էµ� => (Adder(1,2) = 3)
	std::cout << Adder(5) << std::endl;		// �Լ��� �Ű����� 1���� �� -> num2�� ����Ʈ���Էµ� => (Adder(5,2) = 7)
	std::cout << Adder(3,5) << std::endl;	// �Լ��� �Ű����� 2����� �� => (Adder(3,5) = 8)
	
	// * ��°�� *
	// 3
	// 7
	// 8

	std::cout << "------------ < 2) �κ�������Ʈ �� ����  > ----------------" << std::endl;
	// 2) �κ�������Ʈ �� ����
	// ����Ʈ���� �κ��� �ټ� �ִ�
	std::cout << "[3,3,3] : " << BoxVolume(3, 3, 3) << std::endl;		// 3 * 3 * 3
	std::cout << "[5,5,D] : " << BoxVolume(5,5) << std::endl;			// 5 * 5 * 1
	std::cout << "[7,D,D] : " << BoxVolume(7) << std::endl;				// 7 * 1 * 1
	//std::cout << "[D,D,D] : " << BoxVolume() << std::endl;			// ? * 1 * 1  -> �����߻�(length���� ����Ʈ������)
	//std::cout << "[5,D,5] : " << BoxVolume(5, , 5) << std::endl;		// 5 * 5 * 1  -> �����߻�(���� ����)
	
	// * ��°�� *
	// [3, 3, 3] : 27
	// [5, 5, D] : 25
	// [7, D, D] : 7


	return 0;
}


// 1)�Լ�
int Adder(int num1, int num2)				// ���Ǻκп����� ���ص��ȴ�.
{
	return num1 + num2;
}

// 2)�Լ�
int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}