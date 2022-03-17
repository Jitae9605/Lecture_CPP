/*
* Banking System Ver 0.2
* 작성자 : 이지태
* 내용 : Account 클래스 정의, 객체 포인터 배열 적용
* ~ chapter5
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

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;					// 계좌번호
	int balance;				// 잔액
	char *cusName;				// 고객이름
public:
	Account(int ID, int money, char* name) : accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];		// 깊은복사
		strcpy(cusName, name);				
	}

	int GetAccID() { return accID; }

	void Deposit(int money)
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

	void ShowAccInfo()
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

Account* accArr[100];
int accNum = 0;



int main(void)
{
	int Select;

	while (1)
	{
		ShowMenu();
		cout << "선택 : ";
		cin >> Select;
		cout << endl;

		switch (Select)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAcount();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}

	}




	return 0;
}

void ShowMenu(void)				// 메뉴출력
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
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌Id :";
	cin >> id;
	cout << "이름 :";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
	cout << endl << endl;

	accArr[accNum++] = new Account(id, balance, name);
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

void ShowAllAcount(void)		// 잔액조회
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;

	}
}

