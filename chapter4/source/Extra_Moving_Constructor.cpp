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
		cout << "������ȣ��" << endl;
	}

	void viewHuman()
	{
		cout << "�̸� : " << name << ", " << "���� : " << age << endl;
	}
	
};

int main()
{
	Human h1("ȫ�浿", 15);
	h1.viewHuman();

	

	return 0;
}