#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 03_4 Static 멤버변수를 public으로 선언해 바로 접근한다
// 이를통해 static 멤버변수가 객체내에 존재하는게 아님을 알수 있다.


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
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;				// simObjCnt는 객체내에 생성된게 아니다
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;				// simObjCnt는 객체내에 생성된게 아니다



	// * 출력결과 *
	// 0번째 SoSimple 객체
	// 2번째 SoSimple 객체
	// 2번째 SoSimple 객체
	// 2번째 SoSimple 객체

	return 0;
}