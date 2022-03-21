#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 1. 고용관리시스템 - ver3
// 다양한 고용형태(클래스 추가)

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

class TemporaryWorker : public Employee		// 임시직(= 정규직 아님)
{
private:
	int WorkTime;		// 이 달의 일한 시간 합계
	int payPerHour;		// 시간당 급여

public:
	TemporaryWorker(const char*name,int pay)
		:Employee(name),WorkTime(0),payPerHour(pay)
	{ }
	
	void AddWorkTime(int time)			// 일한 시간 추가
	{
		WorkTime += time;
	}

	int GetPay() const					// 이달의 급여
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

class SalesWorker : public PermanentWorker			// 정규직인데 영업직인것
{
private:
	int salesResult;			// 월 판매실적
	double bonusRatio;			// 상여금 비율

public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }

	void AddSaleseResult(int value)		// 영업실적 등록(추가)
	{
		salesResult += value;
	}

	int GetPay() const		// PermanentWorker::GetPay() = 급여
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
	// 1.직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	// 2. 직원등록

	// 2.1 정규직 등록 
	// 이렇게도 등록가능 단, 이렇게 등록하면 내부 수정이 불가능함(이름이 없으므로)
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 2.1.1 영업직 등록
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSaleseResult(7000);		// 영업실적 추가
	handler.AddEmployee(seller);

		
	// 2.2 임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);				// 5시간 일함
	handler.AddEmployee(alba);

	// 3. 이번 달에 지급해야 할 급여의 정보
	handler.ShowAllSalrayInfo();


	// 4. 이번달에 지급해야할 급여의 총합
	handler.ShowTotalSalary();

	// * 출력결과 *
	// salary sum : 0

	return 0;
}
