#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 1. 고용관리시스템 - ver2
// 다양한 고용형태 추가

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
			*/								// 오류 발생! :  
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->Getpay();
			*/								// 오류 발생 :
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
	// salary sum : 0

	return 0;
}
