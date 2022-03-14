/*
* Banking System Ver 0.1
* 작성자 : 이지태
* 내용 : OOP단계별 프로젝트의 기본 틀 구성
*/
#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);				// 메뉴출력
void MakeAccount(void);				// 계좌개설을 위한 함수
void DepositMoney(void);			// 입금
void WithdrawMoney(void);			// 출금
void ShowAllAcount(void);			// 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int accID;					// 계좌번호
	int balance;				// 잔액
	char cusName[NAME_LEN];		// 고객이름
}Account;

Account accArr[100];
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
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
			
	}




	return 0;
}

void ShowMenu(void)				// 메뉴출력
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)			// 계좌개설을 위한 함수
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌Id:";
	cin >> id;
	cout << "이름:";
	cin >> name;
	cout << "입금액";
	cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void)			// 입금
{
	int Money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "입금액 : ";
	cin >> Money;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += Money;
			cout << "입금완료" << endl<<endl;
			return;
		}
	}
	cout << "유효하지 않은 아이디입니다." << endl << endl;
}

void WithdrawMoney(void)		// 출금
{
	int Money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "입금액 : ";
	cin >> Money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if(accArr[i].balance < Money)
			cout << "잔액부족" << endl << endl;
			return;
		}
		accArr[i].balance -= Money;
		cout << "출금완료" << endl << endl;
	}
	cout << "유효하지 않은 아이디입니다." << endl << endl;
}

void ShowAllAcount(void)		// 잔액조회
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌 ID : " << accArr[i].accID << endl;
		cout << "이름 : " << accArr[i].cusName << endl;
		cout << "잔액 : " << accArr[i].balance << endl;

	}
}

