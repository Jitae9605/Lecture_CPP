#include <iostream>
using namespace std;

// 2.����ó�� ��ī���� ����(try, chatch, throw)

int main(void)
{


	int num1, num2;
	cout << "�� ���� ���� �Է� : ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2;
		cout << "�������� �� : " << num1 / num2 << endl;
		cout << "�������� ������ : " << num1 % num2 << endl;
	}
	catch (int expn)	// throw�� ������ �����͸� �޴´�(�ڷ����� ��ġ�ؾ���)
	{
		cout << "������ " << expn << "�� �� �� �����ϴ�." << endl;
		cout << "���α׷��� �ٽ� �����ϼ���." << endl;
	}

	cout << "end of main" << endl;

	// * ��°�� 1 * - �и� 0�� ����
	// �� ���� ���� �Է� : 7 0
	// ������ 0�� �� �� �����ϴ�.
	// ���α׷��� �ٽ� �����ϼ���.
	// end of main

	// * ��°�� 2 * - �����۵� Ȯ��
	// �� ���� ���� �Է� : 100 3
	// �������� �� : 33
	// �������� ������ : 1
	// end of main

	return 0;
}

