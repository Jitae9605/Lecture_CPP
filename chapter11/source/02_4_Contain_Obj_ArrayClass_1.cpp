#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 2_4 ��ü�� ������ ���� �迭 Ŭ������ ����_1 : ��ü�� ���Կ��� ���

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0,int y=0):xpos(x),ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);

};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '['<<pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class bouondChaeckIntArray
{
private:
	Point* arr;
	int arrlen;

	bouondChaeckIntArray(const bouondChaeckIntArray& arr) { }
	bouondChaeckIntArray& operator=(const bouondChaeckIntArray& arr) { }

public:
	bouondChaeckIntArray(int len) :arrlen(len)
	{
		arr = new Point[len];
	}

	Point& operator[] (int idx)							// []������ �����ε�
	{
		if (idx < 0 || idx >= arrlen)		// ����ó�� - �迭�̻��� ����ϸ� ��µǴ� �����Ⱚ ����� ��ü
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	Point operator[] (int idx) const							// []������ �����ε�
	{
		if (idx < 0 || idx >= arrlen)		// ����ó�� - �迭�̻��� ����ϸ� ��µǴ� �����Ⱚ ����� ��ü
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const { return arrlen; }

	~bouondChaeckIntArray()
	{
		delete[]arr;
	}
};

int main(void)
{
	bouondChaeckIntArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i<arr.GetArrLen(); i++)
		cout << arr[i];

	// * ��°�� *
	// [3, 4]
	// [5, 6]
	// [7, 8]

	return 0;
}
