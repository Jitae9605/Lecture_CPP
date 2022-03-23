#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 3_3.배열 new, delete 연산자 오버로딩에 static을 붙여봄(원래 static으로 디폴트임이 결과가 같음으로 증명) 
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);

	static void* operator new (size_t size)						// new 연산자 오버로딩 - 메모리 할당부분만 건들수 있다
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	static void* operator new[](size_t size)						// 배열 new 연산자 오버로딩 - 메모리 할당부분만 건들수 있다
	{
		cout << "operator new [] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

		static void operator delete (void* adr)						// delete 연산자 오버로딩
	{
		cout << "operator delete()" << endl;
		delete[]adr;
	}

	static void operator delete[](void* adr)						// 배열 delete 연산자 오버로딩
	{
		cout << "operator delete[]()" << endl;
		delete[]adr;
	}
	static void Point_static();
};

void Point::Point_static()
{
	cout << "Point::Point_Static()" << endl;
}

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);
	cout << *ptr;
	ptr->Point_static();

	Point* arr = new Point[3];

	delete ptr;
	delete[]arr;

	// * 출력결과 *
	// operator new : 8
	// operator new[] : 24
	// operator delete()
	// operator delete[]()

	// ! new함수는 Point안에 오버로딩되어 있는데 첫 Point를 생성할때조차 new가 왜 오버로딩된 new로서 기능을 하는가?
	// -> new와delete는 static함수로 자동 적용되어 선언되어있다

	return 0;
}
