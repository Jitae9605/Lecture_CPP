#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 3_2 static�� ��� �� ���뼺

using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	// * ��°�� *
	// 1��° SoSimple ��ü
	// 2��° SoSimple ��ü
	// 1��° SoComplex ��ü
	// 2��° SoComplex ��ü

	return 0;
}