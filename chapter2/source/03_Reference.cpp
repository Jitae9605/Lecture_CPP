#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3.�������� ����

// 4)
void SwapByRef2(int& ref1, int& ref2)		// �Ű������� �����ڷ� �޴´�.
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

// 5)
int& RefRetFuncOne(int& ref);
int RefRetFuncTwo(int& ref);

int main(void)
{
	std::cout << "------------ < 1) ������ ����  > ----------------" << std::endl;
	// 1)������ ����
	// �����ڴ� ������ �����̰� �����Ϳ� ��������� �����Ϳʹ� �ٸ��� ����� �ʴ�
	int num1_1;

	// �������� ���
	int* ptr_1 = &num1_1;	// ���� num1_1�� �ּ� ���� ������ ptr_1�� ����

	// �������� ���
	int& num2_1 = num1_1;	// ���� num1_1�� ���� ������ num2_1�� ����
							// num1_1�� ���ϳ��� �±�/������ ���̴� ��!
							// �����ڴ� ����� ���ÿ� �ݵ�� �ٸ� ������ �����Ѿ��Ѵ�.

	std::cout << "------------ < 2) ������ ��뿹��  > ----------------" << std::endl;
	int num1_2 = 1020;
	int& num2_2 = num1_2;

	// ������
	cout << "VAL : " << num1_2 << endl;		// 1020
	cout << "REF : " << num2_2 << endl;		// 1020

	num2_2 = 3047;			// num1_2 ���� 1020���� 3047�� ��
	cout << "VAL : " << num1_2 << endl;		// 3047
	cout << "REF : " << num2_2 << endl;		// 3047

	cout << "VAL : " << &num1_2 << endl;	// num1_2�� �ּҰ�
	cout << "REF : " << &num2_2 << endl;	// num2_2�� �ּҰ�

	// * ��°�� *
	// VAL : 1020
	// REF : 1020
	// VAL : 3047
	// REF : 3047
	// VAL : 0135FCD4 (���� �Ź� �ٸ����� �Ʒ��� �׻� ���� ���� ����Ŵ)
	// REF : 0135FCD4

	std::cout << "------------ < 3) ������ ������  > ----------------" << std::endl;
	// 3) ������ ������

	int num_3 = 12;
	int* ptr_3 = &num_3;
	int** dptr_3 = &ptr_3;

	int& ref_3 = num_3;				// int &ref_3		= num_3
	int* (&pref_3) = ptr_3;			// int *(&pref_3)	= *(ptr_3) = *&num_3 = num_3
	int** (&dpref_3) = dptr_3;		// int **(&dpref_3) = **(dptr_3) = (*(*&ptr_3)) = (*&(*&num_3)) = num_3

	cout << ref_3 << endl;			// num_3 = 12
	cout << *pref_3 << endl;		// *ptr_3 = *&num_3 = num_3 = 12
	cout << **dpref_3 << endl;		// **dptr = *(*&ptr_3) = *ptr_3 = *&num_3 = num_3 = 12

	// * ��°�� *
	// 12
	// 12
	// 12

	std::cout << "------------ < 4) ������ Ȱ��  > ----------------" << std::endl;
	// 4) ������ Ȱ��
	// Call-by-reference �̴� 
	int val1_4 = 10;
	int val2_4 = 20;

	SwapByRef2(val1_4, val2_4);				// �Է¹��� �Ű������� �����ڸ� �Լ����ο� ����� �ش簪�� ��ȯ
	cout << "val1_4 : " << val1_4 << endl;
	cout << "val2_4 : " << val2_4 << endl;

	// * ��°�� *
	// val1_4 : 20
	// val2_4 : 10


	std::cout << "------------ < 5) ��ȯ���� �������� �Լ� > ----------------" << std::endl;
	// 5) ��ȯ���� �������� �Լ�
	// ��ȯ���� �������ϰ�� �� ��ȯ���� �޴� ����� �ڷ����� ���� ����� �޶�����
	// �����ڰ� �� ���� �������, �޴� �����ڵ� �Ű����� ���� �����ڰ� �ȴ�.
	// �����ڰ� �ƴ� ���, �޴� ����� ������ ������ �޴´�.

	int num1_5 = 1;

	// ��ȯ���� �������� �Լ�
	int& num2_5 = RefRetFuncOne(num1_5);					// �̷��� num1_5�� ���� �����ڰ� 2��(num2_5, ref)�� ����ٰ� �Լ��� ���������鼭 1��(ref)�� �Ҹ�
	int num3_5 = RefRetFuncOne(num1_5);						// �̷��� num3_5������ �Լ��� ��ȯ�ϴ� ���� ����ȴ�(�� ����)	
															// ��, num3_5�� ������ ������ �ٸ� �Լ��̴�.
	
	// ��ȯ���� �������� �Լ�
	//int& num4_5 = RefRetFuncTwo(num1_5);					// �����ڰ� �Ϲ� ��ȯ���� ������ ���� 
															// ( �����߻�!!! => �Լ��� ������ ���� ���� ������ ������Ƿ� �����ڰ� ����ų ����� ����)

	int num5_5 = RefRetFuncTwo(num1_5);						// �̰� �׳� ������ ���޴°�

	num1_5++;
	num2_5++;
	num3_5 += 100;

	cout << "num1_5 : " << num1_5 << endl;
	cout << "num2_5 : " << num2_5 << endl;
	cout << "num3_5 : " << num3_5 << endl;				// num3_5�� ������ �Լ����� �����ϱ� ���� �ٸ����� ����
	//cout << "num4_5 : " << num2_5 << endl;			// �����̹Ƿ� �ּ�ó��
	cout << "num5_5 : " << num2_5 << endl;				


	// * ��°�� *
	// num1_5 : 4
	// num2_5 : 4
	// num3_5 : 103
	// num5_5 : 6			


	return 0;
}

// 5)
int& RefRetFuncOne(int& ref)
{
	ref++;
	return ref;
}

int RefRetFuncTwo(int& ref)
{
	ref++;
	return ref;
}