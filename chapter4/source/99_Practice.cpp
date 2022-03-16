#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class Ctime
{
private:
	int hout;			// 시간
	int min;			// 분
	int sec;			// 초

public:
	void SetTime(int ahout, int amin, int asec) // 시간설정
	{
		hout = ahout;
		min = amin;
		sec = asec;

	}

	void getTime()								// 입력한 시간출력
	{
		cout << "현재 시간은 " << hout << "시 " << min << "분 " << sec << "초 입니다." << endl << endl;
	}
};

int main(void)
{
	Ctime t;						// 클래스 객체 생성
	t.SetTime(11, 20, 50);			// 객체내 맴버에 값부여
	t.getTime();					// 객체 출력

	// * 출력 결과 *
	// 현재 시간은 11시 20분 50초 입니다.

	return 0;
}