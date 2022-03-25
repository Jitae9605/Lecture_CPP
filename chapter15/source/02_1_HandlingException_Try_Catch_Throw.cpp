#include <iostream>
using namespace std;

// 2.예외처리 메카니즘 적용(try, chatch, throw)

int main(void)
{


	int num1, num2;
	cout << "두 개의 숫자 입력 : ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2;
		cout << "나눗셈의 몫 : " << num1 / num2 << endl;
		cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
	}
	catch (int expn)	// throw로 던져진 데이터를 받는다(자료형이 일치해야함)
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}

	cout << "end of main" << endl;

	// * 출력결과 1 * - 분모에 0을 대입
	// 두 개의 숫자 입력 : 7 0
	// 제수는 0이 될 수 없습니다.
	// 프로그램을 다시 실행하세요.
	// end of main

	// * 출력결과 2 * - 정상작동 확인
	// 두 개의 숫자 입력 : 100 3
	// 나눗셈의 몫 : 33
	// 나눗셈의 나머지 : 1
	// end of main

	return 0;
}

