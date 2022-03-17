#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 2_2 깊은복사
// 얕은 복사에서 포인터로 참조하는 대상까지 깊게 복사함
// 

using namespace std;

// 1)
class Person
{
private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage)	// 생성자
	{
		int len = strlen(myname) + 1;
		name = new char[len];					
		strcpy(name, myname);
		age = myage;

	}

	Person(const Person& copy) :age(copy.age)			// 복사생성자(깊은복사)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
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
	std::cout << "------------ < 1) 깊은 복사> ----------------" << std::endl;
	// 1) 깊은 복사 
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	//man2.ShowPersonInfo();


	// * 출력결과 *
	// 이름: Lee dong woo
	// 나이 : 29
	// 이름 : Lee dong woo
	// 나이 : 29
	// called destructor!
	// called destructor!

	



	return 0;
}

