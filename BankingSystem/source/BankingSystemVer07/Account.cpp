/*
* Account.cpp
* 작성자 : 이지태
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

int Account::GetAccID() const { return accID; }			// const 추가 (단순 조회 함수 이므로)

void Account::Deposit(int money)					// 가상함수화(이자)
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

void Account::ShowAccInfo() const						// const 추가 (단순 출력 함수이므로)
{
	cout << endl;
	cout << "==============";
	cout << endl;
	cout << "계좌ID : " << accID << endl;
	cout << "이 름 : " << cusName << endl;
	cout << "잔 액 : " << balance << endl;
	cout << "==============";
	cout << endl;
	cout << endl;
}

Account::~Account()
{
	delete[]cusName;
}

