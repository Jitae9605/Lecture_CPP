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