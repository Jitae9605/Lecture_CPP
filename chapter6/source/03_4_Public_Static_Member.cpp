#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 03_4 Static ��������� public���� ������ �ٷ� �����Ѵ�
// �̸����� static ��������� ��ü���� �����ϴ°� �ƴ��� �˼� �ִ�.


using namespace std;

class SoSimple
{
public:
	static int simObjCnt;

public:
	SoSimple()
	{
		simObjCnt++;
	}
};

int SoSimple::simObjCnt = 0;

int main(void)
{
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;				// simObjCnt�� ��ü���� �����Ȱ� �ƴϴ�
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;				// simObjCnt�� ��ü���� �����Ȱ� �ƴϴ�



	// * ��°�� *
	// 0��° SoSimple ��ü
	// 2��° SoSimple ��ü
	// 2��° SoSimple ��ü
	// 2��° SoSimple ��ü

	return 0;
}