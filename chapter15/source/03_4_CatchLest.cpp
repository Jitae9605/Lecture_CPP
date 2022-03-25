#include<iostream>
#include<cstring>
#include<cmath>
#pragma warning(disable:4996)

using namespace std;

// 3_4. 1���� try��ϰ� �������� catch���

int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;

	if (len != 0 && str[0] == '0')
		throw 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i]>'9')
			throw str[i];
		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
	}
	return num;
}

int main(void)
{
	char str1[100];
	char str2[200];

	while (1)
	{
		cout << "�� ���� �� �Է� :";
		cin >> str1 >> str2;

		try
		{
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch (char ch)
		{
			cout << "����" << ch << "�� �ԷµǾ����ϴ�." << endl;
			cout << "���Է��� �����մϴ�." << endl << endl;
		}
		catch (int expn)
		{
			if (expn == 0)
				cout << "0���� �����ϴ� ���ڴ� �ԷºҰ�." << endl;
			else
				cout << "�������� �Է��� �̷�������ϴ�." << endl;
			cout << "���Է��� ����˴ϴ�." << endl << endl;
		
		}

	}
	cout << "���α׷��� �����մϴ�." << endl;

	// * ��°�� *
	// �� ���� �� �Է� :12A 519
	// ����A�� �ԷµǾ����ϴ�.
	// ���Է��� �����մϴ�.
	// 
	// �� ���� �� �Է� : 082 910
	// 0���� �����ϴ� ���ڴ� �ԷºҰ�.
	// ���Է��� ����˴ϴ�.
	// 
	// �� ���� �� �Է� : 123 456
	// 123 + 456 = 579
	// ���α׷��� �����մϴ�.


	return 0;
}