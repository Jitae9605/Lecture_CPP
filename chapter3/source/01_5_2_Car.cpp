#include <iostream>
#include <cstring>
#include "01_5_1_Car.h"


#pragma warning(disable:4996)
using namespace std;


// 차량을 생성하는 함수
void Car::InitMembers(const char* ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

// 차량 상태를 출력하는 함수
void Car::ShowCarState(const Car& car)
{
	cout << "소유자ID : " << car.gamerID << endl;					// 소유자 ID출력
	cout << "연료량 : " << car.fuelGauge << "%" << endl;				// 현재 남은 연료량 출력
	cout << "현재속도 : " << car.curSpeed << "km/s" << endl << endl;	// 현재 속도 출력
}

// 엘셀밟은 상황 출력
void Car::Accel(Car& car)
{
	if (car.fuelGauge <= 0)	// 연료가 0이거나 작으면 엑셀작동X
	{
		return;
	}

	else
		car.fuelGauge -= CAR_CONST::FUEL_STEP;	// 아니면 연료량 줄이고 현재속도에 가속도값 더함

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