#include <iostream>
#include <string.h>

// 2.구조체 내부에 함수 선언

#pragma warning(disable:4996)
using namespace std;

//1)
typedef struct human
{
	char name[20];
	int age;
	char job[10];

	void showdata(void)
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << "살" << endl;
		cout << "직업 : " << job << endl << endl;
	}

}Human;

// 2)
class human_class
{
	char name[20];
	int age;
	char job[10];

	void showdata(void)
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << "살" << endl;
		cout << "직업 : " << job << endl << endl;
	}

};

int main(void)
{
	std::cout << "------------ < 1) 구조체 내부에 함수정의 및 사용  > ----------------" << std::endl;
	// 1) 구조체 내부에 함수정의 및 사용
	Human h1 = { "홍길동", 20, "학생" };
	h1.showdata();

	// * 출력결과 *
	// 이름 : 홍길동
	// 나이 : 20살
	// 직업 : 학생


	std::cout << "------------ < 2) 클래스의 사용과 구조체와의 차이점  > ----------------" << std::endl;
	// 2) 클래스의 사용과 구조체와의 차이점

	return 0;
}