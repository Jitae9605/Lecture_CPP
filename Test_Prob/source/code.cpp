#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Human
{
private:
	char* name;
	int age;
public:
	Human(const char* aname, int aage) :age(aage)
	{
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
	}

	~Human()
	{
		cout << "~Human()" << endl;
	}

	void Print_Human()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl << endl;
	}

	Human operator()(const Human& ref)
	{
		name = ref.name;
		age = ref.age;
		return ref;
	}

	Human& operator=(const Human& ref)
	{
		name = ref.name;
		age = ref.age;
		return *this;
	}
};

int main(void)
{
	Human man("이순신", 50);
	man.Print_Human();

	Human man1(man);
	man1.Print_Human();

	Human xman = man;
	xman.Print_Human();
}