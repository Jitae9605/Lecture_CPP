#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 2_5 객체의 저장을 위한 배열 클래스의 정의_2 : 주소값 저장방식 기반

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);

};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

typedef Point* POINT_PTR;

class bouondChaeckIntArray
{
private:
	POINT_PTR* arr;
	int arrlen;

	bouondChaeckIntArray(const bouondChaeckIntArray& arr) { }
	bouondChaeckIntArray& operator=(const bouondChaeckIntArray& arr) { }

public:
	bouondChaeckIntArray(int len) :arrlen(len)
	{
		arr = new POINT_PTR[len];
	}

	POINT_PTR& operator[] (int idx)							// []연산자 오버로딩
	{
		if (idx < 0 || idx >= arrlen)		// 에러처리 - 배열이상을 출력하면 출력되던 쓰레기값 출력을 대체
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	POINT_PTR operator[] (int idx) const							// []연산자 오버로딩
	{
		if (idx < 0 || idx >= arrlen)		// 에러처리 - 배열이상을 출력하면 출력되던 쓰레기값 출력을 대체
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
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << *arr[i];
	delete arr[0];
	delete arr[1];
	delete arr[2];

	// * 출력결과 *
	// [3, 4]
	// [5, 6]
	// [7, 8]

	return 0;
}
