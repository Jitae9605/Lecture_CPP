#include<iostream>
#include<cstring>
#include<cmath>
#pragma warning(disable:4996)

using namespace std;

int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;

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
		catch(char ch)
		{
			cout << "����" << ch << "�� �ԷµǾ����ϴ�." << endl;
			cout << "���Է��� �����մϴ�." << endl << endl;
		}

	}
	cout << "���α׷��� �����մϴ�." << endl;

	// * ��°�� *
	// �� ���� �� �Է� :123 3A5
	// ����A�� �ԷµǾ����ϴ�.
	// ���Է��� �����մϴ�.
	// 
	// �� ���� �� �Է� : 28F 211
	// ����F�� �ԷµǾ����ϴ�.
	// ���Է��� �����մϴ�.
	// 
	// �� ���� �� �Է� : 231 891
	// 231 + 891 = 1122
	// ���α׷��� �����մϴ�.

	return 0;
}