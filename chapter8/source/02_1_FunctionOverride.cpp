#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

class First
{
public:
	void MyFunc() 
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:
	void MyFunc()
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:
	void MyFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};


int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	delete tptr;

	// * 출력결과 *
	// FirstFunc
	// SecondFunc
	// ThirdFunc

	return 0;
}