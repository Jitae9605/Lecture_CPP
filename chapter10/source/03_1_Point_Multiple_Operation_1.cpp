#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3. 자료형이 다른 두 피연산자를 대상으로 하는 연산
// 좌표값에 배수를 적용해 반환하는 클래스 함수 작성

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

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = pos * 3 * 2;
	cpy.ShowPosition();

	// * 출력결과 *
	// [3, 6]
	// [6, 12]


	return 0;
}
