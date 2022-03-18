#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// * 이동생성자
//	복사생성자는 객체를 만들고 임시객체를 만들고(생성자 호출, 역할끝나고 소멸자 호출) 각각의 멤버를 복사한다 
//	즉, 단계가 많고 느리다
// 
//	이에비해, 이동생성자는 객체가 만들어지고 이동대상이 되는 객체가 만들어진 객체를 가리키게 하는 것 이다.

class Human
{
private:
	char name[20];
	int age;
public:
	Human(const char* aname, int aage) : age(aage)		// 생성자
	{
		cout << "생성자호출" << endl;
		strcpy(name, aname);
		
	}

	Human(const Human& other)	// lvalue 참조						// 복사생성자
	{
		cout << "복사 생성자 호출" << endl;
		strcpy(name, other.name);
		age = other.age;
	}

	Human(Human&& other)		// rvalue 참조						// 이동생성자
	{
		cout << "이동 생성자 호출" << endl;
		strcpy(name, other.name);
		age = other.age;
	}

	void viewHuman()
	{
		cout << "이름 : " << name << ", " << "나이 : " << age << endl << endl;
	}
	
};

int main()
{
	Human h1("홍길동", 15);
	h1.viewHuman();

	Human h2(h1);				
	h2.viewHuman();

	Human h3(move(h1));			// 매개변수를 rvalue로 바꾼다
	h3.viewHuman();
	h1.viewHuman();


	

	return 0;
}