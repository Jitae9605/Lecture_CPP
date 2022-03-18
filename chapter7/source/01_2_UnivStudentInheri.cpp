#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage,const char* myname) :age(myage)
	{
		strcpy(name, myname);
	}

	void whatYourName() const
	{
		cout << "My name is " << name << endl;
	}

	void HowOldAreYou() const
	{
		cout << "I'm " << age << "years old" << endl;
	}
};

class UnivStudent : public Person			// 상속받음
{
private:
	char major[50];

public:
	UnivStudent(const char* myname, int myage, const char* mymajor)
		: Person(myage, myname)				// 상속받은거 멤버 초기화(Person(int myage,const char* myname))
	{
		strcpy(major, mymajor);
	}

	void WhoAreYou() const
	{
		whatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd1.WhoAreYou();


	// * 출력결과 *
	// My name is Lee
	// I'm 22years old
	// My major is Computer eng.
	// 
	// My name is Lee
	// I'm 22years old
	// My major is Computer eng.
	return 0;
}
