#include <iostream>

#pragma warning(disable:4996)

using namespace std;

// 1.��������
// ������ �����Ͽ� �ܺ� ���ȵ �ſ� ����

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
		cout << "�� ��� : " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "�� �ϴ� : " << '[' << lowRight.x << ", ";
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

	// * ��°�� *
	// �� ��� : [-2, 4]
	// �� �ϴ� : [5, 9]


	return 0;
}