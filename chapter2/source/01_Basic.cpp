#include <iostream>

// 1. ���� �� �߿�����Ʈ

int main(void)
{
	// 1) const�� ������
	int val1, val2, val3;

	const int num = 10;						// ���� num�� ����� 
	const int* ptr1 = &val1;				// ������ ptr1�� ���� val1�� �� ����Ұ�
	int * const ptr2 = &val2;				// ������ ptr2�� ���ȭ
	const int* const ptr3 = &val3;			// ������ ptr3�� ���ȭ �� ptr3�� ���� val3�� �� ����Ұ�

	// 2) ������, ����, ��

	// ������(Data)		= ���������� ����Ǵ� ����
	// ����(stack)		= �������� �� �Ű������� ����Ǵ� ����
	// ��(Heap)			= malloc �Լ� ȣ�⿡ ���� ���α׷��� ����Ǵ� �������� �������� �Ҵ��� �̷����� ����


	// 3) Call-by-value / Call-by-reference

	/*
	
	void SwapByValue(int num1,int num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
		// Call-by-value
	}

	Void SwapByRef(int*ptr1,int*ptr2)
	{
		int temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
		// Call-by-reference
	}

	*/
	return 0;
}