#include <iostream>
#include <string.h>

// �ڵ��� ���̽� ��Ȳ ����� �Լ�

#pragma warning(disable:4996)
using namespace std;

#define ID_LEN		20
#define	MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10


struct Car	// �ڵ��� ����ü
{
	char gamerID[ID_LEN];		// ������ID
	int fuelGauge;				// ���ᷮ
	int curSpeed;				// ����ӵ�

};

// ���� ���¸� ����ϴ� �Լ�
void ShowCarState(const Car& car)
{
	cout << "������ID : " << car.gamerID << endl;					// ������ ID���
	cout << "���ᷮ : " << car.fuelGauge <<"%" << endl;				// ���� ���� ���ᷮ ���
	cout << "����ӵ� : " << car.curSpeed <<"km/s" << endl << endl;	// ���� �ӵ� ���
}

// �������� ��Ȳ ���
void Accel(Car& car)
{
	if (car.fuelGauge <= 0)	// ���ᰡ 0�̰ų� ������ �����۵�X
	{
		return;
	}

	else
		car.fuelGauge -= FUEL_STEP;	// �ƴϸ� ���ᷮ ���̰� ����ӵ��� ���ӵ��� ����

	if (car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		return;
	}

	car.curSpeed += ACC_STEP;
}

void Break(Car& car)
{
	if (car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}

	car.curSpeed -= BRK_STEP;
}


int main(void)
{
	Car run99 = { "run99",100,0 };
	Accel(run99);
	Accel(run99);
	ShowCarState(run99);
	Break(run99);
	ShowCarState(run99);

	Car sped77 = { "sped77",100,0 };
	Accel(sped77);
	Break(sped77);
	ShowCarState(sped77);

	// * ��°�� *
	// ������ID: run99
	// ���ᷮ : 96 %
	// ����ӵ� : 20km / s
	// 
	// ������ID : run99
	// ���ᷮ : 96 %
	// ����ӵ� : 10km / s
	// 
	// ������ID : sped77
	// ���ᷮ : 98 %
	// ����ӵ� : 0km / s
	
	return 0;
}