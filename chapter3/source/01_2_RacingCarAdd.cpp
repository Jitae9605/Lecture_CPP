#include <iostream>
#include <string.h>

// 자동차 레이싱 상황 만드는 프로그램
//	2) 함수들을 구조체 내부에 삽입
//		(선언만 내부에 하고 정의를 외부에 뺄수도 있다. 단, 그럴경우 함수정의시 '반환형 구조체명::함수명(매개변수)'형태로 정의해야함)

#pragma warning(disable:4996)
using namespace std;

#define ID_LEN		20
#define	MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10


struct Car	// 자동차 구조체
{
	char gamerID[ID_LEN];		// 소유자ID
	int fuelGauge;				// 연료량
	int curSpeed;				// 현재속도

	// 차량 상태를 출력하는 함수
	void ShowCarState(const Car& car)
	{
		cout << "소유자ID : " << car.gamerID << endl;					// 소유자 ID출력
		cout << "연료량 : " << car.fuelGauge << "%" << endl;				// 현재 남은 연료량 출력
		cout << "현재속도 : " << car.curSpeed << "km/s" << endl << endl;	// 현재 속도 출력
	}

	// 엘셀밟은 상황 출력
	void Accel(Car& car)
	{
		if (car.fuelGauge <= 0)	// 연료가 0이거나 작으면 엑셀작동X
		{
			return;
		}

		else
			car.fuelGauge -= FUEL_STEP;	// 아니면 연료량 줄이고 현재속도에 가속도값 더함

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
};







int main(void)
{
	Car run99 = { "run99", 100, 0 };
	run99.Accel(run99);
	run99.Accel(run99);
	run99.ShowCarState(run99);
	run99.Break(run99);
	run99.ShowCarState(run99);

	Car sped77 = { "sped77", 100, 0 };
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