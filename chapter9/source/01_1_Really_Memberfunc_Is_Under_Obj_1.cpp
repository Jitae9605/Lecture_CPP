#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 1. ��ü�ȿ� ����Լ��� ������ �����ϴ°�?

class Data
{
private:
	int data;

public:
	Data(int num):data(num)
	{ }

	void ShowData() { cout << "Data : " << data << endl; }
	void Add(int num) { data += num; }
};

int main(void)
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();

	// * ��°�� *
	// Data : 32
	return 0;
}