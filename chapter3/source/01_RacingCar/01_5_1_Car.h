#ifndef __CAR_H__
#define __CAR_H__

// �ڵ��� ���̽� ��Ȳ ����� ���α׷�
// 5)-1 ������ ������� ( Ŭ�������� �� �������)



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

#endif