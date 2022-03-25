#include <iostream>
using namespace std;

// 4.���ø��� ����ƽ 
// 4_1.�Լ����ø��� static ��������
// �Լ����ø� ���ο� ����� static�� ���ø��Լ����� ���� ����Ȱ��̴�

template <typename T>
void ShowStaticValue(void)
{
	static T num = 0;
	num += 1;
	cout << num << " ";
}

int main(void)
{
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	cout << endl;
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	cout << endl;
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();

	// * ��°�� *
	// 1 2 3
	// 1 2 3
	// 1 2 3

	// num�� static�ε� �������� ���ߴ� -> �ش� ���ø� ������ ����������.
	return 0;
}