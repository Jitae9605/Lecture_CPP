#include<iostream>

// 2. �Է�(std::cin >> ������)

int main(void)
{
	// 1) �ܼ��Է¹���
	int val1;
	std::cout << "ù��° �����Է�: ";
	std::cin >> val1;					// std::cin�� �̿��� �Է¹������� val1�� ����(���߲��� ��������)

	int val2;
	std::cout << "�ι�° �����Է�: ";
	std::cin >> val2;					// std::cin�� �̿��� �Է¹������� val2�� ����(���߲��� ��������)

	int result = val1 + val2;			
	std::cout << "�������: " << result << std::endl;

	// * ��°�� *
	// ù��° �����Է� : 10		
	// �ι�° �����Է� : 20
	// ������� : 30


	// 2) ����
	int val1_2 = 0, val2_2 = 0;
	int result_2 = 0;

	std::cout << "�ΰ��� �����Է�: ";
	std::cin >> val1 >> val2;

	if (val1_2 < val2_2)							// val1_2 �� val2_2���� �۴ٸ�
	{
		for (int i = val1_2 + 1; i < val2_2; i++)
		{
			result_2 += i;							// (val1_2 + 1)���� (val2_2 - 1)������ ����  ��� ���� result_2�� ����
		}
	}

	else
	{
		for (int i = val2_2 + 1; i < val1_2; i++)	// val1_2 �� val2_2���� ũ�ų� ���ٸ� (�׳� else�̹Ƿ�)
		{
			result_2 += i;							// (val2_2 + 1)���� (val1_2 - 1)������ ���� ��� ���� result_2�� ����
		}

		std::cout << "�� �������� ���� ��: " << result_2 << std::endl;
	}


	return 0;
}