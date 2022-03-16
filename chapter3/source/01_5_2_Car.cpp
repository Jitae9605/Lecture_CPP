#include <iostream>
#include <cstring>
#include "01_5_1_Car.h"


#pragma warning(disable:4996)
using namespace std;


// ������ �����ϴ� �Լ�
void Car::InitMembers(const char* ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

// ���� ���¸� ����ϴ� �Լ�
void Car::ShowCarState(const Car& car)
{
	cout << "������ID : " << car.gamerID << endl;					// ������ ID���
	cout << "���ᷮ : " << car.fuelGauge << "%" << endl;				// ���� ���� ���ᷮ ���
	cout << "����ӵ� : " << car.curSpeed << "km/s" << endl << endl;	// ���� �ӵ� ���
}

// �������� ��Ȳ ���
void Car::Accel(Car& car)
{
	if (car.fuelGauge <= 0)	// ���ᰡ 0�̰ų� ������ �����۵�X
	{
		return;
	}

	else
		car.fuelGauge -= CAR_CONST::FUEL_STEP;	// �ƴϸ� ���ᷮ ���̰� ����ӵ��� ���ӵ��� ����

	if (car.curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
	{
		car.curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	car.curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break(Car& car)
{
	if (car.curSpeed < CAR_CONST::BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}

	car.curSpeed -= CAR_CONST::BRK_STEP;
}