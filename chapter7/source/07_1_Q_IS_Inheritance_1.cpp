#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// Is - A 관계를 통한 상속 문제 1번
// Squre area

class Rectangle
{
private:
	int a1;
	int a2;
	int area;

public:
	Rectangle(int aa1, int aa2) : a1(aa1),a2(aa2)
	{
		area = a1 * a2;
	}

	void ShowAreaInfo()
	{
		cout << "면적: " << area << endl << endl;
	}
};

class Square : public Rectangle
{
private:
	int a;
	int area;
public:
	Square(int aa) : a(aa), Rectangle(aa,aa)
	{
		area = aa * aa;
	}

};

int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	


	return 0;
}
