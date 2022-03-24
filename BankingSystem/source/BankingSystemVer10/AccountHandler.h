#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include"Account.h"
#include"BoundCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr;
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;				// �޴����
	void MakeAccount(void);					// ���°����� ���� �Լ�
	void DepositMoney(void);				// �Ա�
	void WithdrawMoney(void);				// ���
	void ShowAllAccInfo(void) const;		// �ܾ���ȸ
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

#endif