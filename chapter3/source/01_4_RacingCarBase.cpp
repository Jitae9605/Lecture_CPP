#include <iostream>
#include <string.h>

// �ڵ��� ���̽� ��Ȳ ����� ���α׷�
// 4) �Լ����� �� ������� / �Լ����� / ���ι� ���� ������ ���� ���� ����


#pragma warning(disable:4996)
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}


class Car	// �ڵ��� ����ü
{
	

private:
	char gamerID[CAR_CONST::ID_LEN];		// ������ID
	int fuelGauge;				// ���ᷮ
	int curSpeed;				// ����ӵ�
public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState(const Car& car);
	void Accel(Car& car);
	void Break(Car& car);
	
};
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

int main(void)
{
	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel(run99);
	run99.Accel(run99);
	run99.ShowCarState(run99);
	run99.Break(run99);
	run99.ShowCarState(run99);

	Car sped77;
	sped77.InitMembers("sped77", 100);
	sped77.Accel(sped77);
	sped77.Break(sped77);
	sped77.ShowCarState(sped77);

	// * ��°�� *
	// ������ID: run99
	// ���ᷮ : 96%
	// ����ӵ� : 20km/s
	// 
	// ������ID : run99
	// ���ᷮ : 96%
	// ����ӵ� : 10km/s
	// 
	// ������ID : sped77
	// ���ᷮ : 98%
	// ����ӵ� : 0km/s

	return 0;
}