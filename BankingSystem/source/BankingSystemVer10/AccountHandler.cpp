
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"AccountHandler.h"
#include"BankingCommonDecl.h"
#include"Account.h"
#include"String.h"

AccountHandler::AccountHandler() :accNum(0)
{ }

void AccountHandler::ShowMenu(void) const				// �޴����
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

void AccountHandler::MakeAccount(void)			// ���°����� ���� �Լ�
{
	cout << endl;
	int Select;

	cout << "[������������]" << endl;

	cout << "1.���뿹�ް���" << endl;
	cout << "2.�ſ�ŷڰ���" << endl;
	cout << "���� : ";
	cin >> Select;
	cout << endl << endl;
	if (Select == NOMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();

}

void AccountHandler::DepositMoney(void)			// �Ա�
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

void AccountHandler::WithdrawMoney(void)		// ���
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

void AccountHandler::ShowAllAccInfo(void) const		// �ܾ���ȸ
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;

	}
}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	String name;
	//char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> balance;
	cout << "������ : ";
	cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	String name;
	//char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> balance;
	cout << "������ : ";
	cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC) : ";
	cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate,LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate,LEVEL_C);
	}
}
