#include <iostream>
#include <cstring>
#include "01_5_1_Car.h"


#pragma warning(disable:4996)
using namespace std;

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