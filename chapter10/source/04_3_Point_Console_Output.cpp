#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 4_3 좌표출력

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{ }

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point&pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point pos1(1, 3);
	cout << pos1;
	Point pos2(101, 303);
	cout << pos2;

	// * 출력결과 *
	// [1, 3]
	// [101, 303]

	return 0;
}