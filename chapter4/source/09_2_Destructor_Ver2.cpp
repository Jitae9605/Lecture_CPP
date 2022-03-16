#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 09_1_Destructor_Ver1에서 객체배열을 추가함
// 

using namespace std;

class Person
{
private:
	char* name;
	int age;

public:
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
	Person parr[3];						// 객체배열선언
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];					// strptr에 동적할당
		strcpy(strptr, namestr);				// 입력받은 값을 동적할당으로 전달
		parr[i].SetPersonInfo(strptr, age);		// SetPersonInfo(char* myname, int myage)
	}

	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	
	


	return 0;

	// * 출력결과 *
	// called Person()
	// called Person()
	// called Person()
	// 이름 : 한지수
	// 나이 : 21
	// 이름 : 양은정
	// 나이 : 31
	// 이름 : 이한영
	// 나이 : 34
	// 이름 : 한지수, 나이 : 21
	// 이름 : 양은정, 나이 : 31
	// 이름 : 이한영, 나이 : 34
	// called destructor!
	// called destructor!
	// called destructor!
}