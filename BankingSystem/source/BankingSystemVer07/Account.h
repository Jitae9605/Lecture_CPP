/*
* Account.h
* 작성자 : 이지태
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__



class Account
{
private:
	int accID;					// 계좌번호
	int balance;				// 잔액
	char* cusName;				// 고객이름

public:
	Account(int ID, int money, const char* name);
	Account(const Account& ref);

	int GetAccID() const; 							
	virtual void Deposit(int money);				
	int Withdarw(int money);
	void ShowAccInfo() const;						
	~Account();
};

#endif