#include<iostream>
using namespace std;

// 1.���ø�
// 

template <typename T>		// �Լ����ø�
T Add(T num1, T num2)		// ���⼭ T�� ������ �ڷ����̴� ���߿� �츮�� ����
{
	return num1 + num2;
}

int main(void)
{
	// �Լ����ø��� ���� ����Ǵ� �Լ��� == �Լ����ø�
	cout << Add<int>(15, 20) << endl;			// T�ڸ��� int, double�� ��
	cout << Add<double>(2.9,3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14,2.75) << endl;

	// * ��°�� *
	// 35
	// 6.6
	// 6
	// 5.89

	return 0;
}