#include <iostream>

// 5.함수오버로딩
// c++은 동일한 함수명이어도 매개변수 갯수 및 자료형 등을 통해 구분하여 다른 동작을 가능하게끔 허용한다(c는 허용X)
// 즉, 같은 이름의 함수가 여러개일수 있다

// 1) 함수
int MyFunc(int num)
{
	num++;
	return num;

}

int MyFunc(int a, int b)
{
	return a + b;
}

// 2)함수
void MyFunc_2(void)
{
	std::cout << "MyFunc_2(void) called" << std::endl;
}

void MyFunc_2(char c)
{
	std::cout << "MyFunc_2(char c) called" << std::endl;
}

void MyFunc_2(int a, int b)
{
	std::cout << "MyFunc_2(int a, int b) called" << std::endl;
}

int main(void)
{
	std::cout << "------------ < 1) 기초 > ----------------" << std::endl;
	// 1) 기초
	std::cout << MyFunc(20) <<std::endl;		// MyFunc(int num)
	std::cout << MyFunc(30, 40) << std::endl;		// MyFunc(int a, int b)

	// * 출력결과 *
	// 21
	// 70
	
	std::cout << "------------ < 2) 기본 > ----------------" << std::endl;
	// 2)기본
	MyFunc_2();
	MyFunc_2('A');
	MyFunc_2(12, 13);

	// * 출력결과 *
	// MyFunc_2(void) called
	// MyFunc_2(char c) called
	// MyFunc_2(int a, int b) called
	


	return 0 ;
}