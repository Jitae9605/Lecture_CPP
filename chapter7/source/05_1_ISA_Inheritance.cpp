#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// Is-A 관계를 통한 상속
// TabletNotebook is a NotebookComp 
// NotebookComp is a Computer
// 즉, TabletNotebook -> NotebookComp -> Computer

class Computer
{
private:
	char owner[50];

public:
	Computer(const char* name)
	{
		strcpy(owner, name);
	}

	void Calculate()
	{
		cout << "요청 내용을 계산합니다." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;
public:
	NotebookComp(const char* name, int initChag)
		: Computer(name), Battery(initChag)
	{ }
	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}

		cout << "이동하면서 ";
		Calculate();
		UseBattery();
	}

	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp
{
private:
	char regstPenModel[50];

public:
	TabletNotebook(const char* name, int initChag,const char* pen)
		: NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}

	void Write(const char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}

		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "등록된 펜이 아닙니다." << endl;
			return;
		}

		cout << "필기내용을 처리합니다." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("이수종", 5);
	TabletNotebook tn("정수영", 5,"ISA-241-242");
	nc.MovingCal();
	tn.Write("ISA-241-242");


	// * 출력결과 *
	// 이동하면서 요청 내용을 계산합니다.
	// 필기내용을 처리합니다.

	return 0;
}