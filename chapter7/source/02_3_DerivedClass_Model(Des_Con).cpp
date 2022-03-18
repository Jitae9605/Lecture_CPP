#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

// 유도클래스의 생성자/소멸자 정의의 모델

class Person
{
private:
	char* name;
public:
	Person(const char*myname)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}

	~Person()
	{
		delete[]name;
	}

	void whatYourName() const
	{
		cout << "My name is " << name << endl;
	}

	
};

class UnivStudent : public Person			// 상속받음
{
private:
	char* major;

public:
	UnivStudent(const char* myname, const char* mymajor)
		: Person( myname)				// 상속받은거 멤버 초기화(Person(int myage,const char* myname))
	{
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}

	~UnivStudent()
	{
		delete[]major;
	}

	void WhoAreYou() const
	{
		whatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent st1("Lee", "Computer eng.");
	st1.WhoAreYou();

	UnivStudent st2("Yoon", "Electronic eng.");
	st2.WhoAreYou();


	// * 출력결과 *
	// My name is Lee
	// My major is Computer eng.
	//
	// My name is Yoon
	// My major is Electronic eng.
	
	return 0;
}
