#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 09_2_Destructor_Ver2의 객체배열을 객체포인터배열로 바꿈
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

	Person()		// 객체배열을 이용하면 인자를 줄수 없기에 반드시 사전에 디폴트를 수정해야 초기화시킬수 있다.	
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char* myname, int myage)		// 객체배열 내부의 멤버에 각각의 인자전달
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << ", ";
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
	Person* parr[3];						// 객체배열선언
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		parr[i] = new Person(namestr, age);  // SetPersonInfo(char* myname, int myage)
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0];
	delete parr[1];
	delete parr[2];





	return 0;

	// * 출력결과 *
	// 이름 : 안수희
	// 나이: 31
	// 이름 : 이한오
	// 나이 : 39
	// 이름 : 강인한
	// 나이 : 19
	// 이름 : 안수희, 나이 : 31
	// 이름 : 이한오, 나이 : 39
	// 이름 : 강인한, 나이 : 19
	// called destructor!
	// called destructor!
	// called destructor!