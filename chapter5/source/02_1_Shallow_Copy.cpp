#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 2_1 얕은복사
// 멤버대 멤버로 진행되는 복사
// 멤버변수가 힙의 메모리공간을 참조하는경우 오류가 발생할 수 있다(동적할당, 포인터를 이용하는 경우 발생)

using namespace std;

// 1)
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
	std::cout << "------------ < 1) 얕은복사의 위험성 > ----------------" << std::endl;
	// 1) 얕은복사의 위험성 
	Person man1("Lee dong woo", 29);
	Person man2 = man1;					// 얕은복사
	man1.ShowPersonInfo();
	//man2.ShowPersonInfo();


	// * 출력결과 *
	// 이름: Lee dong woo
	// 나이 : 29
	// 이름 : Lee dong woo
	// 나이 : 29
	// called destructor!
	
	//  - 오류발생 - ( called destructor! 가 2번 출력되야하는데 1번만 출력됬고 오류메세지가 출력됨 )
	// char* name은 "Lee dong woo"의 시작주소를 받은것이므로 delete를 통해 man1이 사라지면 
	// 그 주소를 복사해간 man2는 man1이 delete될때 이미 헤제된것 대상의 주소(공간)을 다시 해제하고자 하므로 오류발생
	


	return 0;
}

