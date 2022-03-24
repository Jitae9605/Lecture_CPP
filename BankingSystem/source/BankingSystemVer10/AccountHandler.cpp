
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"AccountHandler.h"
#include"BankingCommonDecl.h"
#include"Account.h"
#include"String.h"

AccountHandler::AccountHandler() :accNum(0)
{ }

void AccountHandler::ShowMenu(void) const				// 메뉴출력
{
	cout << endl;
	cout << "-----Menu-----" << endl;
	cout << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입  금" << endl;
	cout << "3. 출  금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl << endl;
}

void AccountHandler::MakeAccount(void)			// 계좌개설을 위한 함수
{
	cout << endl;
	int Select;

	cout << "[계좌종류선택]" << endl;

	cout << "1.보통예급계좌" << endl;
	cout << "2.신용신뢰계좌" << endl;
	cout << "선택 : ";
	cin >> Select;
	cout << endl << endl;
	if (Select == NOMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();

}

void AccountHandler::DepositMoney(void)			// 입금
{
	cout << endl;
	int Money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "입금액 : ";
	cin >> Money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(Money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 아이디입니다." << endl << endl;
}

void AccountHandler::WithdrawMoney(void)		// 출금
{
	cout << endl;
	int Money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "출금액 : ";
	cin >> Money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdarw(Money) == 0)
				cout << "잔액부족" << endl << endl;
			return;
		}
		cout << "출금완료" << endl << endl;
		return;
	}
	cout << "유효하지 않은 아이디입니다." << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const		// 잔액조회
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

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
	cout << "이자율 : ";
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

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
	cout << "이자율 : ";
	cin >> interRate;
	cout << "신용등급(1toA, 2toB, 3toC) : ";
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
