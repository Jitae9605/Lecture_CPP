#include <iostream>
#include <string.h>

// 자동차 레이싱 상황 만드는 프로그램
// 4) 함수선언 및 상수지정 / 함수정의 / 메인문 으로 나누기 위한 정리 과정


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


class Car	// 자동차 구조체
{
	

private:
	char gamerID[CAR_CONST::ID_LEN];		// 소유자ID
	int fuelGauge;				// 연료량
	int curSpeed;				// 현재속도
public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState(const Car& car);
	void Accel(Car& car);
	void Break(Car& car);
	
};
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

	// * 출력결과 *
	// 소유자ID: run99
	// 연료량 : 96%
	// 현재속도 : 20km/s
	// 
	// 소유자ID : run99
	// 연료량 : 96%
	// 현재속도 : 10km/s
	// 
	// 소유자ID : sped77
	// 연료량 : 98%
	// 현재속도 : 0km/s

	return 0;
}