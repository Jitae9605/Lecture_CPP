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
class human_class	// 은닉, 캡슐화 - 멤버함수를 통해서만 값을 입력/생성/변경 등이 가능함
{
public:								// public으로 설정(원래 이러면 안됨 - 은닉의 역할이 없어짐. 이럴거면 그냥 struct를 써야함)	
	char name[20];					// (디폴트 = private)
	int age;						// (디폴트 = private)
	char job[10];					// (디폴트 = private)
	

	// 생성자 = 초기화시키는 기능을함(현시점에서는)
	/*human_class (char* a, int b, char* c)
	{
		name = a;
		age = b;
		job = c;
	}*/

	// class 내부함수
	void showdata(void)				// public
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
	// 클래스는 내부의 멤버들이 private로 디폴트설정이라 외부에서의 멤버삽입이 불가능
	// 여기서는 억지로 public으로 멤버를 설정해 삽입한다.
	human_class hc1{ "홍길동", 20, "학생" };
	hc1.showdata();

	// * 출력결과 *
	// 이름 : 홍길동
	// 나이 : 20살
	// 직업 : 학생

	return 0;
}