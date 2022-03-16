#include <iostream>
#include"07_1_Point.h"

#pragma warning(disable:4996)

using namespace std;

// 02_2_Point.cpp �� ������ �߰��� ����

Point::Point(const int &xpos, const int &ypos)
{
	x = xpos;
	y = ypos;
}

int Point::GetX() const
{
	return x;
}
int Point::GetY() const
{
	return y;
}
bool Point::SetX(int xpos)
{
	if (xpos < 0 || xpos > 100)
	{
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	x = xpos;
	return true;
}
bool Point::SetY(int ypos)
{
	if (ypos < 0 || ypos > 100)
	{
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	y = ypos;
	return true;
}