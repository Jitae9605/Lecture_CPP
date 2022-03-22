#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 1. 객체안에 멤버함수가 실제로 존재하는가?

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

	// * 출력결과 *
	// Data : 32
	return 0;
}