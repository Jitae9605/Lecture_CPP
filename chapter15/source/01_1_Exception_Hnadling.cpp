#include <iostream>
using namespace std;

// 1.예외처리

int main(void)
{

	// 예외처리하지 않은경우
	//int num1, num2;
	//cout << "두 개의 숫자 입력 : ";
	//cin >> num1 >> num2;

	//cout << "나눗셈의 몫 : " << num1 / num2 << endl;
	//cout << "나눗셈의 나머지 : " << num1 % num2 << endl;

	// 이렇게 작성하면 이상한 값이 들어갔을때 계산이 안된다 ex)num2에 0이 들어갈경우 등

	int num1, num2;
	
	while (1)
	{
		cout << "두 개의 숫자 입력 : ";
		cin >> num1 >> num2;
		if (num2 <= 0) cout << "잘못된 입력입니다 다시 시도해주세요" << endl;
		else break;
	}

	cout << "나눗셈의 몫 : " << num1 / num2 << endl;
	cout << "나눗셈의 나머지 : " << num1 % num2 << endl;

	return 0;

}