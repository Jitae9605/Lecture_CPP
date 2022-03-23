#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 3_3.�迭 new, delete ������ �����ε��� static�� �ٿ���(���� static���� ����Ʈ���� ����� �������� ����) 
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);

	static void* operator new (size_t size)						// new ������ �����ε� - �޸� �Ҵ�κи� �ǵ�� �ִ�
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	static void* operator new[](size_t size)						// �迭 new ������ �����ε� - �޸� �Ҵ�κи� �ǵ�� �ִ�
	{
		cout << "operator new [] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

		static void operator delete (void* adr)						// delete ������ �����ε�
	{
		cout << "operator delete()" << endl;
		delete[]adr;
	}

	static void operator delete[](void* adr)						// �迭 delete ������ �����ε�
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

	// * ��°�� *
	// operator new : 8
	// operator new[] : 24
	// operator delete()
	// operator delete[]()

	// ! new�Լ��� Point�ȿ� �����ε��Ǿ� �ִµ� ù Point�� �����Ҷ����� new�� �� �����ε��� new�μ� ����� �ϴ°�?
	// -> new��delete�� static�Լ��� �ڵ� ����Ǿ� ����Ǿ��ִ�

	return 0;
}
