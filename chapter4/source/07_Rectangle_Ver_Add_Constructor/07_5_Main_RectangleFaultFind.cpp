#include <iostream>
#include"07_1_Point.h"
#include"07_3_Rectangle.h"
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();

	// * 출력결과 *
	// 좌 상단 : [1, 1]
	// 우 하단 : [5, 5]

	return 0;

}