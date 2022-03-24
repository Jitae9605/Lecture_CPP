#include<iostream>
#include"PointTemplate.h"
#include"PointTamplate.cpp"			// 템플릿은 이걸 넣어줘야한다.
using namespace std;

int main(void)
{
	Point<int>pos1(3, 4);
	pos1.ShowPosition();
	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();

	// * 출력결과 *
	// [3, 4]
	// [2.4, 3.6]
	// [P, F]

	return 0;
}