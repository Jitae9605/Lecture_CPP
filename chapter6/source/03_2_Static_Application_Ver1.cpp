#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 3_2 static의 사용 및 유용성

using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	// * 출력결과 *
	// 1번째 SoSimple 객체
	// 2번째 SoSimple 객체
	// 1번째 SoComplex 객체
	// 2번째 SoComplex 객체

	return 0;
}