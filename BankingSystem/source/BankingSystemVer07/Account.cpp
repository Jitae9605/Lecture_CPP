/*
* Account.cpp
* �ۼ��� : ������
*/

#include "BankingCommonDecl.h"
#include "Account.h"


Account::Account(int ID, int money, const char* name) : accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance)
	{
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}

int Account::GetAccID() const { return accID; }			// const �߰� (�ܼ� ��ȸ �Լ� �̹Ƿ�)

void Account::Deposit(int money)					// �����Լ�ȭ(����)
{
	balance += money;
}

int Account::Withdarw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const						// const �߰� (�ܼ� ��� �Լ��̹Ƿ�)
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

Account::~Account()
{
	delete[]cusName;
}

