#ifndef __CAR_H__
#define __CAR_H__

// 자동차 레이싱 상황 만드는 프로그램
// 5)-1 분할한 헤더파일 ( 클래스선언 및 상수지정)



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

#endif