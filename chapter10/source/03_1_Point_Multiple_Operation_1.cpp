#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3. �ڷ����� �ٸ� �� �ǿ����ڸ� ������� �ϴ� ����
// ��ǥ���� ����� ������ ��ȯ�ϴ� Ŭ���� �Լ� �ۼ�

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

	// * ��°�� *
	// [3, 6]
	// [6, 12]


	return 0;
}
