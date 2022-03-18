#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Human
{
private:
	char name[20];
	int age;
public:
	Human(const char* aname, int aage) : age(aage)
	{
		strcpy(name, aname);
		cout << "생성자호출" << endl;
	}

	void viewHuman()
	{
		cout << "이름 : " << name << ", " << "나이 : " << age << endl;
	}
	
};

int main()
{
	Human h1("홍길동", 15);
	h1.viewHuman();

	

	return 0;
}