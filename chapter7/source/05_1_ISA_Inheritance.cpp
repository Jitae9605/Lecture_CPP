#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// Is-A ���踦 ���� ���
// TabletNotebook is a NotebookComp 
// NotebookComp is a Computer
// ��, TabletNotebook -> NotebookComp -> Computer

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
		cout << "��û ������ ����մϴ�." << endl;
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
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}

		cout << "�̵��ϸ鼭 ";
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
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}

		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�." << endl;
			return;
		}

		cout << "�ʱ⳻���� ó���մϴ�." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("�̼���", 5);
	TabletNotebook tn("������", 5,"ISA-241-242");
	nc.MovingCal();
	tn.Write("ISA-241-242");


	// * ��°�� *
	// �̵��ϸ鼭 ��û ������ ����մϴ�.
	// �ʱ⳻���� ó���մϴ�.

	return 0;
}