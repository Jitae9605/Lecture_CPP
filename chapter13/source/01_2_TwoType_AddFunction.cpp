#include<iostream>
using namespace std;

// 1_2. �� ����Ÿ���� Add Function
// 

template <typename T>		// �Լ����ø�
T Add(T num1, T num2)		// ���⼭ T�� ������ �ڷ����̴� ���߿� �츮�� ����
{
	cout << "T Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2)
{
	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)
{
	// �Լ����ø��� ���� ����Ǵ� �Լ��� == �Լ����ø�
	cout << Add(5, 7) << endl;			
	cout << Add(3.7, 7.5) << endl;
	cout << Add<int>(5, 7) << endl;
	cout << Add<double>(3.7, 7.5) << endl;

	// * ��°�� *
	// Add(int num1, int num2)
	// 12
	// Add(double num1, double num2)
	// 11.2
	// T Add(T num1, T num2)
	// 12
	// T Add(T num1, T num2)
	// 11.2

	return 0;
}