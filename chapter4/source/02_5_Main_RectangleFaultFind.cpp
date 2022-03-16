#include <iostream>
#include"02_1_Point.h"
#include"02_3_Rectangle.h"
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	Point pos1;
	if (!pos1.InitMembers(-2, 4))
		cout << "초기화 실패" << endl;
	if (!pos1.InitMembers(2, 4))
		cout << "초기화 실패" << endl;

	Point pos2;
	if (!pos2.InitMembers(5, 9))
		cout << "초기화 실패" << endl;

	Rectangle rec;
	if (!rec.InitMembers(pos2, pos1))
		cout << "직사각형 초기화 실패" << endl;

	if (!rec.InitMembers(pos1, pos2))
		cout << "직사각형 초기화 실패" << endl;
	
	rec.ShowRecInfo();

	// * 출력결과 *
	// 벗어난 범위의 값 전달
	// 초기화 실패
	// 잘못된 위치정보 전달
	// 직사각형 초기화 실패
	// 좌 상단 : [2, 4]
	// 우 하단 : [5, 9]

	return 0;

}