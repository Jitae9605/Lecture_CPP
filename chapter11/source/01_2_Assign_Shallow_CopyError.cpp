#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1_2. 디폴트 대입연산자의 문제점

class Person
{
private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];					// 오류의 원인
		strcpy(name, myname);
		age = myage;

	}

	Person& operator=(const Person& ref)
	{
		delete[]name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}

	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	// * 출력결과 *
	// 이름 : Lee dong woo
	// 나이: 29
	// 이름 : Lee dong woo
	// 나이 : 29
	// called destructor!
	// called destructor!


	return 0;
}

