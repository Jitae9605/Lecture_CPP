#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 1. �������ý��� - ver3
// �پ��� �������(Ŭ���� �߰�)

class Employee
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}

	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
};

class TemporaryWorker : public Employee		// �ӽ���(= ������ �ƴ�)
{
private:
	int WorkTime;		// �� ���� ���� �ð� �հ�
	int payPerHour;		// �ð��� �޿�

public:
	TemporaryWorker(const char*name,int pay)
		:Employee(name),WorkTime(0),payPerHour(pay)
	{ }
	
	void AddWorkTime(int time)			// ���� �ð� �߰�
	{
		WorkTime += time;
	}

	int GetPay() const					// �̴��� �޿�
	{
		return WorkTime * payPerHour;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << endl << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;

public:
	PermanentWorker(const char* name, int money) : salary(money), Employee(name)
	{ }

	int Getpay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << Getpay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0)
	{ }

	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalrayInfo() const
	{
		/*
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
			*/								// ���� �߻�! :  
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->Getpay();
			*/								// ���� �߻� :
		cout << "salary sum : " << sum << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

class SalesWorker : public PermanentWorker			// �������ε� �������ΰ�
{
private:
	int salesResult;			// �� �ǸŽ���
	double bonusRatio;			// �󿩱� ����

public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }

	void AddSaleseResult(int value)		// �������� ���(�߰�)
	{
		salesResult += value;
	}

	int GetPay() const		// PermanentWorker::GetPay() = �޿�
	{
		return PermanentWorker::Getpay() + (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;;
	}
};

int main(void)
{
	// 1.���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	// 2. �������

	// 2.1 ������ ��� 
	// �̷��Ե� ��ϰ��� ��, �̷��� ����ϸ� ���� ������ �Ұ�����(�̸��� �����Ƿ�)
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 2.1.1 ������ ���
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSaleseResult(7000);		// �������� �߰�
	handler.AddEmployee(seller);

		
	// 2.2 �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);				// 5�ð� ����
	handler.AddEmployee(alba);

	// 3. �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalrayInfo();


	// 4. �̹��޿� �����ؾ��� �޿��� ����
	handler.ShowTotalSalary();

	// * ��°�� *
	// salary sum : 0

	return 0;
}
