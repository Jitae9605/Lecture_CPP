#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 9. 소멸자
// 

using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1; // 널문자를 포함(+1)
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()						// 소멸자
	{
		delete[]name;
		cout << "called destructor!" << endl;	// 이거 적으려고 굳이 소멸자를 명시한것 없어도 자동으로 소멸자가 디폴트로 있음! 
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();


	return 0;

	// * 출력결과 *
	// 이름 : Lee dong woo
	// 나이: 29
	// 이름 : Jang dong gun
	// 나이 : 41
	// called destructor!
	// called destructor!
}