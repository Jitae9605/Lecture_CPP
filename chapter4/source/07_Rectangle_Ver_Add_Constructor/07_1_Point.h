#ifndef __POINT_H__
#define __POINT_H__

// 02_1_Point.h 에 생성자 추가한 버전

#pragma warning(disable:4996)

using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	Point(const int& xpos, const int& ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};

#endif