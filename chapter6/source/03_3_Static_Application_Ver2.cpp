#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 03_2_Static_Application_Ver1 ���� ���������� static ��������� ������ ���� �� ������ ���ɼ��� ���δ�.

using namespace std;

class SoSimple
{
private:
	static int simObjCnt;

public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
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
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
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

	// * ��°�� *
	// 1��° SoSimple ��ü
	// 2��° SoSimple ��ü
	// 1��° SoComplex ��ü
	// 2��° SoComplex ��ü

	return 0;
}