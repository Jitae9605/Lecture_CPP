/*
* Banking System Ver 0.5
* �ۼ��� : ������
* ���� : ����� ���� ���뼺 ����(Entity / Control Ŭ��������) 
* + chapter7 ��  ����
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);				// �޴����
void MakeAccount(void);				// ���°����� ���� �Լ�
void DepositMoney(void);			// �Ա�
void WithdrawMoney(void);			// ���
void ShowAllAcount(void);			// �ܾ���ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// Ŭ���� �̸� : Account
// Ŭ���� ���� : Entity Ŭ����

class Account
{
private:
	int accID;					// ���¹�ȣ
	int balance;				// �ܾ�
	char* cusName;				// �����̸�

public:
	Account(int ID, int money, char* name) : accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	Account(const Account& ref) : accID(ref.accID), balance(ref.balance)
	{
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}

	int GetAccID() const { return accID; }			// const �߰� (�ܼ� ��ȸ �Լ� �̹Ƿ�)

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdarw(int money)
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAccInfo() const						// const �߰� (�ܼ� ��� �Լ��̹Ƿ�)
	{
		cout << endl;
		cout << "==============";
		cout << endl;
		cout << "����ID : " << accID << endl;
		cout << "�� �� : " << cusName << endl;
		cout << "�� �� : " << balance << endl;
		cout << "==============";
		cout << endl;
		cout << endl;
	}

	~Account()
	{
		delete[]cusName;
	}

};

// Ŭ���� �̸� : AccountHandler
// Ŭ���� ���� : Control Ŭ����

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;

public:
	AccountHandler():accNum(0)
	{ }

	void ShowMenu(void) const				// �޴����
	{
		cout << endl;
		cout << "-----Menu-----" << endl;
		cout << endl;
		cout << "1. ���°���" << endl;
		cout << "2. ��  ��" << endl;
		cout << "3. ��  ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl << endl;
	}

	void MakeAccount(void)			// ���°����� ���� �Լ�
	{
		cout << endl;
		int id;
		char name[NAME_LEN];
		int balance;

		cout << "[���°���]" << endl;
		cout << "����Id :";
		cin >> id;
		cout << "�̸� :";
		cin >> name;
		cout << "�Աݾ� : ";
		cin >> balance;
		cout << endl << endl;

		accArr[accNum++] = new Account(id, balance, name);
	}

	void DepositMoney(void)			// �Ա�
	{
		cout << endl;
		int Money;
		int id;
		cout << "[�� ��]" << endl;
		cout << "����ID : ";
		cin >> id;
		cout << "�Աݾ� : ";
		cin >> Money;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetAccID() == id)
			{
				accArr[i]->Deposit(Money);
				cout << "�ԱݿϷ�" << endl << endl;
				return;
			}
		}
		cout << "��ȿ���� ���� ���̵��Դϴ�." << endl << endl;
	}

	void WithdrawMoney(void)		// ���
	{
		cout << endl;
		int Money;
		int id;
		cout << "[�� ��]" << endl;
		cout << "����ID : ";
		cin >> id;
		cout << "��ݾ� : ";
		cin >> Money;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetAccID() == id)
			{
				if (accArr[i]->Withdarw(Money) == 0)
					cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
		cout << "��ȿ���� ���� ���̵��Դϴ�." << endl << endl;
	}

	void ShowAllAccInfo(void) const		// �ܾ���ȸ
	{
		for (int i = 0; i < accNum; i++)
		{
			accArr[i]->ShowAccInfo();
			cout << endl;

		}
	}
	~AccountHandler()
	{
		for (int i = 0; i < accNum; i++)
			delete accArr[i];
	}

};


int main(void)
{
	int Select;
	AccountHandler manager;

	while (1)
	{
		manager.ShowMenu();
		cout << "���� : ";
		cin >> Select;
		cout << endl;

		switch (Select)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}

	}
	return 0;
}

