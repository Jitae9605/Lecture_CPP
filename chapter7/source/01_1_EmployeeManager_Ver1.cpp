#include <iostream>
#pragma warning(disable:4996)

// 1. �������ý��� - ver1
// 

using namespace std;

class PermanentWorker
{
private:
	char name[100];
	int salary;

public:
	PermanentWorker(const char* name, int money) : salary(money)
	{
		strcpy(this->name, name);
	}

	int Getpay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		cout << "name : " << name << endl;
		cout << "salary : " << Getpay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler():empNum(0)
	{ }

	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalrayInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->Getpay();
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
	// name : KIM
	// salary: 1000
	// 
	// name : LEE
	// salary : 1500
	// 
	// name : JUN
	// salary : 2000
	// 
	// salary sum : 4500

	return 0;
}
