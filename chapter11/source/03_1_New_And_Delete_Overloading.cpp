#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 3_1. new, delete ������ �����ε� 
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new (size_t size)						// new ������ �����ε� - �޸� �Ҵ�κи� �ǵ�� �ִ�
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete (void* adr)						// delete ������ �����ε�
	{
		cout << "operator delete ()" << endl;
		delete[]adr;
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);		
	cout << *ptr;
	delete ptr;

	// * ��°�� *
	// operator new : 8
	// [3, 4]
	// operator delete ()

	// ! new�Լ��� Point�ȿ� �����ε��Ǿ� �ִµ� ù Point�� �����Ҷ����� new�� �� �����ε��� new�μ� ����� �ϴ°�?
	// -> new��delete�� static�Լ��� �ڵ� ����Ǿ� ����Ǿ��ִ�

	return 0;
}
