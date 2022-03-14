/*
* Banking System Ver 0.1
* �ۼ��� : ������
* ���� : OOP�ܰ躰 ������Ʈ�� �⺻ Ʋ ����
*/
#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);				// �޴����
void MakeAccount(void);				// ���°����� ���� �Լ�
void DepositMoney(void);			// �Ա�
void WithdrawMoney(void);			// ���
void ShowAllAcount(void);			// �ܾ���ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int accID;					// ���¹�ȣ
	int balance;				// �ܾ�
	char cusName[NAME_LEN];		// ���̸�
}Account;

Account accArr[100];
int accNum = 0;

int main(void)
{
	int Select;

	while (1)
	{
		ShowMenu();
		cout << "���� : ";
		cin >> Select;
		cout << endl;

		switch (Select)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAcount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
			
	}




	return 0;
}

void ShowMenu(void)				// �޴����
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void)			// ���°����� ���� �Լ�
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����Id:";
	cin >> id;
	cout << "�̸�:";
	cin >> name;
	cout << "�Աݾ�";
	cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void)			// �Ա�
{
	int Money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
	cin >> Money;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += Money;
			cout << "�ԱݿϷ�" << endl<<endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ���̵��Դϴ�." << endl << endl;
}

void WithdrawMoney(void)		// ���
{
	int Money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
	cin >> Money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if(accArr[i].balance < Money)
			cout << "�ܾ׺���" << endl << endl;
			return;
		}
		accArr[i].balance -= Money;
		cout << "��ݿϷ�" << endl << endl;
	}
	cout << "��ȿ���� ���� ���̵��Դϴ�." << endl << endl;
}

void ShowAllAcount(void)		// �ܾ���ȸ
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "���� ID : " << accArr[i].accID << endl;
		cout << "�̸� : " << accArr[i].cusName << endl;
		cout << "�ܾ� : " << accArr[i].balance << endl;

	}
}

