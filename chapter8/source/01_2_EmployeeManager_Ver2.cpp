#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 1. �������ý��� - ver2
// �پ��� ������� �߰�

class Emplyee
{
private:
	char name[100];
public:
	Emplyee(const char* name)
	{
		strcpy(this->name, name);
	}

	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
};

class PermanentWorker : public Emplyee
{
private:
	int salary;

public:
	PermanentWorker(const char* name, int money) : salary(money),Emplyee(name)
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
	Emplyee* empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0)
	{ }

	void AddEmployee(Emplyee* emp)
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

int main(void)
{
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	// �������
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalrayInfo();


	// �̹��޿� �����ؾ��� �޿��� ����
	handler.ShowTotalSalary();

	// * ��°�� *
	// salary sum : 0

	return 0;
}
