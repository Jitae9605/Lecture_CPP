#include <iostream>
#include"07_3_Rectangle.h"
#pragma warning(disable:4996)

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
	: upLeft(x1, y1), lowRight(x2, y2)		// ����̴ϼȶ�����
{
	// empty
}

void Rectangle::ShowRecInfo(void) const
{
	cout << "�� ��� : " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "�� �ϴ� : " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl << endl;
}
