/*
* Account.h
* ?ۼ??? : ??????
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accID;					// ???¹?ȣ
	int balance;				// ?ܾ?
	char* cusName;				// ?????̸?

public:
	Account(int ID, int money, const char* name);
	Account(const Account& ref);
	Account& operator=(const Account& ref);

	int GetAccID() const; 							
	virtual void Deposit(int money);				
	int Withdarw(int money);
	void ShowAccInfo() const;						
	~Account();
};

#endif