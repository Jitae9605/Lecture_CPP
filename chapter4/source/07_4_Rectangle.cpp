#include <iostream>
#include"07_3_Rectangle.h"
#pragma warning(disable:4996)

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
	: upLeft(x1, y1), lowRight(x2, y2)		// 멤버이니셜라이저
{
	// empty
}

void Rectangle::ShowRecInfo(void) const
{
	cout << "좌 상단 : " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "우 하단 : " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl << endl;
}
