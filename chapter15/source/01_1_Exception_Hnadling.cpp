#include <iostream>
using namespace std;

// 1.����ó��

int main(void)
{

	// ����ó������ �������
	//int num1, num2;
	//cout << "�� ���� ���� �Է� : ";
	//cin >> num1 >> num2;

	//cout << "�������� �� : " << num1 / num2 << endl;
	//cout << "�������� ������ : " << num1 % num2 << endl;

	// �̷��� �ۼ��ϸ� �̻��� ���� ������ ����� �ȵȴ� ex)num2�� 0�� ����� ��

	int num1, num2;
	
	while (1)
	{
		cout << "�� ���� ���� �Է� : ";
		cin >> num1 >> num2;
		if (num2 <= 0) cout << "�߸��� �Է��Դϴ� �ٽ� �õ����ּ���" << endl;
		else break;
	}

	cout << "�������� �� : " << num1 / num2 << endl;
	cout << "�������� ������ : " << num1 % num2 << endl;

	return 0;

}