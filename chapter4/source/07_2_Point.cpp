#include <iostream>
#include"07_1_Point.h"

#pragma warning(disable:4996)

using namespace std;

// 02_2_Point.cpp 에 생성자 추가한 버전

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
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	x = xpos;
	return true;
}
bool Point::SetY(int ypos)
{
	if (ypos < 0 || ypos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	y = ypos;
	return true;
}