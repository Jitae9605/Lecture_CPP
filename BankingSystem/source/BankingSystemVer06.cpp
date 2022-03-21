/*
* Banking System Ver 0.6
* 작성자 : 이지태
* 내용 : 가상함수도입 + 계좌종류 추가(보통예금,신용신뢰 - 이자개념 도입 -> Deposit함수 수정(가상함수화)
* + chapter8 의  내용
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);				// 메뉴출력
void MakeAccount(void);				// 계좌개설을 위한 함수
void DepositMoney(void);			// 입금
void WithdrawMoney(void);			// 출금
void ShowAllAcount(void);			// 잔액조회

// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 신용등급에 따른 이자율
enum{LEVEL_A=7, LEVEL_B = 4, LEVEL_C = 2};

// 계좌종류
enum{NOMAL = 1, CREDIT = 2};

// 클래스 이름 : Account
// 클래스 유형 : Entity 클래스

class Account
{
private:
	int accID;					// 계좌번호
	int balance;				// 잔액
	char* cusName;				// 고객이름

public:
	Account(int ID, int money, const char* name) : accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	Account(const Account& ref) : accID(ref.accID), balance(ref.balance)
	{
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}

	int GetAccID() const { return accID; }			// const 추가 (단순 조회 함수 이므로)

	virtual void Deposit(int money)					// 가상함수화(이자)
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

	void ShowAccInfo() const						// const 추가 (단순 출력 함수이므로)
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

	~Account()
	{
		delete[]cusName;
	}

};

// 클래스 이름 : NormalAccount
// 클래스 유형 : Entity 클래스

class NormalAccount : public Account
{
private:
	int interRate;		//이자율(단위:%)
public:
	NormalAccount(int ID, int money, const char*name, int rate) 
		: Account(ID, money, name),interRate(rate)
	{ }

	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));	// 이자추가
	}
};

// 클래스 이름 : HighCreditAccount
// 클래스 유형 : Entity 클래스

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID,int money,const char*name,int rate,int special)
		: NormalAccount(ID,money,name,rate),specialRate(special)
	{ }

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);							// 원금과 이자추가
		Account::Deposit(money * (specialRate / 100.0));		// 특별이자 추가
	}
};


// 클래스 이름 : AccountHandler
// 클래스 유형 : Control 클래스

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;

public:
	AccountHandler() :accNum(0)
	{ }

	void ShowMenu(void) const				// 메뉴출력
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

	void MakeAccount(void)			// 계좌개설을 위한 함수
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

	void DepositMoney(void)			// 입금
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

	void WithdrawMoney(void)		// 출금
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

	void ShowAllAccInfo(void) const		// 잔액조회
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
	
protected:
	void MakeNormalAccount(void)
	{
		int id;
		char name[NAME_LEN];
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

	void MakeCreditAccount(void)
	{
		int id;
		char name[NAME_LEN];
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
			accArr[accNum++] = new NormalAccount(id, balance, name, LEVEL_A);
			break;
		case 2:
			accArr[accNum++] = new NormalAccount(id, balance, name, LEVEL_B);
			break;
		case 3:
			accArr[accNum++] = new NormalAccount(id, balance, name, LEVEL_C);
		}
	}


};


int main(void)
{
	int Select;
	AccountHandler manager;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택 : ";
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


