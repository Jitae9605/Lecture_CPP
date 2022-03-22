#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1_2. ������ �����ε��� �ΰ��� ���_2

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

	friend Point operator+(const Point& pos1, const Point& pos2);	// friend �� ������ xpos,ypos�� private�̱� �����̴�.
	friend Point operator+(int n, const Point& other);
};

Point operator+(const Point& pos1, const Point& pos2)			// operator+��� �Լ��� ���� (�����ڿ����ε� *ȣ���� ������'+'�� �ᵵ ����)
{	
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);	// Point ��ü2���� �޾Ƽ� �� xpos, ypos���� ���ؼ� Point��ü pos�� ���� 
	return pos;													//  pos�� ��ȯ
}

Point operator+(int n, const Point& other)						// ���
{
	Point pos(n + other.xpos, n + other.ypos);	
	return pos;										
}



int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = operator+(pos1,pos2);
	Point pos4 = pos1 + pos2;	// = 	pos1.operator+(pos2);			// ���⼭ +�� opertator+�̴� 
																		// operator+�� ������ �������� �ʾҴٸ� + �� �۵����� �ʴ´�
	Point pos5 = operator+(100,pos1);
	Point pos6 = 100 + pos1;	// =	operator+(100,pos1); 
	Point pos7 = pos1 + 100;	// ������ �����ִ� 
							


	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();
	pos6.ShowPosition();
	pos7.ShowPosition();


	return 0;

	// * ��°�� *
	// [3, 4]
	// [10, 20]
	// [13, 24]
	// [13, 24]
	// [103, 104]
	// [103, 104]
	// [103, 4]

}
