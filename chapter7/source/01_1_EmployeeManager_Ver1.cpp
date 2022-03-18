#include <iostream>
#pragma warning(disable:4996)

// 1. 고용관리시스템 - ver1
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
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	// 직원등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// 이번 달에 지급해야 할 급여의 정보
	handler.ShowAllSalrayInfo();


	// 이번달에 지급해야할 급여의 총합
	handler.ShowTotalSalary();

	// * 출력결과 *
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
