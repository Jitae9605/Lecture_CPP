#include <iostream>
using namespace std;

// 3.참조자의 이해

int main(void)
{
	std::cout << "------------ < 1) 참조자 기초  > ----------------" << std::endl;
	// 1)참조자 기초
	// 참조자는 일종의 변수이고 포인터와 비슷하지만 포인터와는 다르고 어렵지 않다
	int num1_1;

	// 포인터의 경우
	int* ptr_1 = &num1_1;	// 변수 num1_1의 주소 값을 포인터 ptr_1에 저장

	// 참조자의 경우
	int& num2_1 = num1_1;	// 변수 num1_1에 대한 참조자 num2_1를 선언
							// num1_1에 또하나의 태그/별명을 붙이는 것!
							// 참조자는 선언과 동시에 반드시 다른 변수를 가리켜야한다.

	std::cout << "------------ < 2) 참조자 사용예시  > ----------------" << std::endl;
	int num1_2 = 1020;
	int& num2_2 = num1_2;

	// 변경전
	cout << "VAL : " << num1_2 << endl;		// 1020
	cout << "REF : " << num2_2 << endl;		// 1020

	num2_2 = 3047;			// num1_2 값도 1020에서 3047이 됨
	cout << "VAL : " << num1_2 << endl;		// 3047
	cout << "REF : " << num2_2 << endl;		// 3047

	cout << "VAL : " << &num1_2 << endl;	// num1_2의 주소값
	cout << "REF : " << &num2_2 << endl;	// num2_2의 주소값

	// * 출력결과 *
	// VAL : 1020
	// REF : 1020
	// VAL : 3047
	// REF : 3047
	// VAL : 0135FCD4 (값은 매번 다르지만 아래와 항상 같은 값을 가리킴)
	// REF : 0135FCD4

	

	return 0;
}