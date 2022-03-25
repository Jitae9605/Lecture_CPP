#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// 4_2.��������� �������� �ùķ��̼��� ���� ��Ӱ��迡 �ִ� ����Ŭ������ �����غ���
class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class DepositException : public AccountException
{
private:
	int reqDep;	// ��û�Աݾ�
public:
	DepositException(int money) :reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: " << reqDep << "�� �ԱݺҰ�" << endl;
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
		cout << "[���� �޽���: �ܾ�" << balance << ", �ܾ׺���]" << endl;
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
		cout << "�ܰ� : " << balance << endl << endl;
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

	// * ��°�� *
	// [���� �޽���: -300�� �ԱݺҰ�
	// �ܰ�: 7000

	// [���� �޽��� : �ܾ�3500, �ܾ׺���]
	// �ܰ� : 3500

	// ����ó��Ŭ������ ��Ӱ���� �ϳ��� ���ο� �θ�Ŭ������ �����ѵ� ������ ������ �Ʒ��� �ڵ尡 �ۼ��� ���������.

	return 0;

}