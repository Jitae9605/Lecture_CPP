/*
* NormalAccount.h
* �ۼ��� : ������
*/


#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include"Account.h"
#include"String"

class NormalAccount : public Account
{
private:
	int interRate;		//������(����:%)
public:
	//NormalAccount(int ID, int money, const char* name, int rate)
	NormalAccount(int ID, int money, String name, int rate)
		: Account(ID, money, name), interRate(rate)
	{ }

	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));	// �����߰�
	}
};

#endif