#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// 4_2.현금인출기 현금인출 시뮬레이션을 통해 상속관계에 있는 예외클래스를 설꼐해보자
class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class DepositException : public AccountException
{
private:
	int reqDep;	// 요청입금액
public:
	DepositException(int money) :reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: " << reqDep << "는 입금불가" << endl;
	}
};

class WithdarwException : public AccountException
{
private:
	int balance;
public:
	WithdarwException(int money) :balance(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: 잔액" << balance << ", 잔액부족]" << endl;
	}
};



class Account
{
private:
	char accNum[50];
	int balance;
public:
	Account(const char* acc, int money) :balance(money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (AccountException)
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void withdraw(int money) throw (AccountException)
	{
		if (money > balance)
			throw WithdarwException(balance);
		balance -= money;
	}
	void ShowMoney()
	{
		cout << "잔고 : " << balance << endl << endl;
	}
};

int main(void)
{
	Account myAcc("56789-827120", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMoney();

	try
	{
		myAcc.withdraw(3500);
		myAcc.withdraw(4500);
	}
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMoney();

	// * 출력결과 *
	// [예외 메시지: -300는 입금불가
	// 잔고: 7000

	// [예외 메시지 : 잔액3500, 잔액부족]
	// 잔고 : 3500

	// 예외처리클래스를 상속관계로 하나의 새로운 부모클래스를 선언한뒤 버츄얼로 묶으면 아래의 코드가 작성시 깔끔해진다.

	return 0;

}