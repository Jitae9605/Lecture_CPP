#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__


#include"Account.h"




class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;				// 메뉴출력
	void MakeAccount(void);					// 계좌개설을 위한 함수
	void DepositMoney(void);				// 입금
	void WithdrawMoney(void);				// 출금
	void ShowAllAccInfo(void) const;		// 잔액조회
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

#endif