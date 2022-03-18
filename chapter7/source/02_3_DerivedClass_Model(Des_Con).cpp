#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

// ����Ŭ������ ������/�Ҹ��� ������ ��

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

class UnivStudent : public Person			// ��ӹ���
{
private:
	char* major;

public:
	UnivStudent(const char* myname, const char* mymajor)
		: Person( myname)				// ��ӹ����� ��� �ʱ�ȭ(Person(int myage,const char* myname))
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


	// * ��°�� *
	// My name is Lee
	// My major is Computer eng.
	//
	// My name is Yoon
	// My major is Electronic eng.
	
	return 0;
}
