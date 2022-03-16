#include <iostream>

#pragma warning(disable:4996)

using namespace std;

// 1.정보은닉
// 종보를 은닉하여 외부 보안등에 매우 유리

// 1)

class Point
{
public:
	int x;
	int y;
};

class Rectangle
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo(void)
	{
		cout << "좌 상단 : " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "우 하단 : " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl << endl;
	}
};

int main(void)
{
	
	std::cout << "------------ < 1) RectagleFault > ----------------" << std::endl;
	// 1) RectagleFault
	Point pos1_1 = { -2,4 };
	Point pos2_1 = { 5,9 };
	Rectangle rec = { pos1_1,pos2_1 };
	rec.ShowRecInfo();

	// * 출력결과 *
	// 좌 상단 : [-2, 4]
	// 우 하단 : [5, 9]


	return 0;
}