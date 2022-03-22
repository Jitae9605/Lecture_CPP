#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1_1. ������ �����ε��� �ΰ��� ���_1

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

	Point operator+(const Point& ref)		// operator+��� �Լ��� ���� (�����ڿ����ε� ** ȣ���� ������'+'�� �ᵵ ����)
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);	// Point ��ü2���� �޾Ƽ� �� xpos, ypos���� ���ؼ� Point��ü pos�� ���� 
		return pos;										//  pos�� ��ȯ
	}

	Point operator+(int n)					// ������ �����ε��� �Լ� �����ε��� ��������
	{
		return Point(xpos + n, ypos + n);
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);
	Point pos4 = pos1 + pos2;	// = 	pos1.operator+(pos2);			// ���⼭ +�� opertator+�̴� 
																		// operator+�� ������ �������� �ʾҴٸ� + �� �۵����� �ʴ´�
	Point pos5 = pos1.operator+(100);
	Point pos6 = pos1 + 100;	// =	pos1.operator+(100);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();
	pos6.ShowPosition();

	return 0;

	// * ��°�� *
	// [3, 4]
	// [10, 20]
	// [13, 24]
	// [13, 24]
	// [103, 104]
	// [103, 104]
}
