#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3_2 ���꿡 ���� ��ȯ��Ģ�� �����ǰ� �ϱ�

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

	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}

};

Point operator*(int times, Point& ref)
{
	return ref * times;
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = 3 * pos;
	cpy.ShowPosition();

	cpy = 3 * pos * 2;
	cpy.ShowPosition();

	// * ��°�� *
	// [3, 6]
	// [6, 12]


	return 0;
}
