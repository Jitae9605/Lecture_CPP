#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 03_2_Static_Application_Ver1 에서 전역변수를 static 멤버변수로 선언해 보안 및 오류의 가능성을 줄인다.

using namespace std;

class SoSimple
{
private:
	static int simObjCnt;

public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;

class SoComplex
{
private:
	static int cmxObjCnt;

public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

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