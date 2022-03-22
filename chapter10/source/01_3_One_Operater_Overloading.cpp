#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1_3. 단항 연산자의 오버로딩
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

	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return*this;
	}

	friend Point& operator--(Point& ref);
	friend ostream& operator<<(ostream& os, const Point& other);
};

Point& operator--(Point& ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;

	return ref;
}

ostream& operator<<(ostream& os, const Point& other)		// << 연산자 오버로딩
{
	os << '[' << other.xpos << ", " << other.ypos << ']' << endl;
	return os;
}


int main(void)
{
	Point pos(1, 2);

	++pos;
	pos.ShowPosition();

	--pos;
	pos.ShowPosition();

	++(++pos);
	pos.ShowPosition();

	--(--pos);
	pos.ShowPosition();

	cout << pos << endl;;

	return 0;
}
