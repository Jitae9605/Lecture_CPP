#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1_2. 연산자 오버로딩의 두가지 방법_2

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

	friend Point operator+(const Point& pos1, const Point& pos2);	// friend 인 이유는 xpos,ypos가 private이기 때문이다.
	friend Point operator+(int n, const Point& other);
};

Point operator+(const Point& pos1, const Point& pos2)			// operator+라는 함수를 만듬 (연산자오버로딩 *호출은 연산자'+'만 써도 가능)
{	
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);	// Point 객체2개를 받아서 각 xpos, ypos끼리 더해서 Point객체 pos에 저장 
	return pos;													//  pos를 반환
}

Point operator+(int n, const Point& other)						// 상수
{
	Point pos(n + other.xpos, n + other.ypos);	
	return pos;										
}



int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = operator+(pos1,pos2);
	Point pos4 = pos1 + pos2;	// = 	pos1.operator+(pos2);			// 여기서 +는 opertator+이다 
																		// operator+를 사전에 정의하지 않았다면 + 는 작동하지 않는다
	Point pos5 = operator+(100,pos1);
	Point pos6 = 100 + pos1;	// =	operator+(100,pos1); 
	Point pos7 = pos1 + 100;	// 순서가 연관있다 
							


	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();
	pos6.ShowPosition();
	pos7.ShowPosition();


	return 0;

	// * 출력결과 *
	// [3, 4]
	// [10, 20]
	// [13, 24]
	// [13, 24]
	// [103, 104]
	// [103, 104]
	// [103, 4]

}
