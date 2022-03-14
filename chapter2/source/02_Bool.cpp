#include <iostream>
using namespace std;

// 1. true와 false
// c++ 에서는 더이상 별도의 헤더파일을 포함하지 않아도 bool자료형 및 true/false를 사용할수 있다.

// 2) 
bool IsPositive(int num)
{
	if (num <= 0)
		return false;
	else
		return true;
}

int main(void)
{
	std::cout << "------------ < 1) true/false 이해  > ----------------" << std::endl;
	// 1) true/false 이해
	// c++ 에서는 더이상 별도의 헤더파일을 포함하지 않아도 bool자료형 및 true/false를 사용할수 있다.
	int num_1 = 10;
	int i = 0;

	cout << "true: " << true << endl;					// 단순 출력시 true	= 1
	cout << "false: " << false << endl;					//            false = 0

	while (true)				// while은 조건식이 true인 동안 반복
	{
		cout << i++ << ' ';
		if (i > num_1)			// 무한반복while 탈출
			break;				
	}
	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;				// 1 = int			=> 4 byte
	cout << "sizeof 0: " << sizeof(1) << endl;				// 0 = int			=> 4 byte
	cout << "sizeof true: " << sizeof(true) << endl;		// true = bool		=> 1 byte
	cout << "sizeof false: " << sizeof(false) << endl;		// false = bool		=> 1 byte

	// * 출력결과 *
	// true: 1
	// false : 0
	// 0 1 2 3 4 5 6 7 8 9 10
	// sizeof 1 : 4
	// sizeof 0 : 4
	// sizeof true : 1
	// sizeof false : 1


	std::cout << "------------ < 2) bool 자료형의 이해  > ----------------" << std::endl;
	// 2) bool 자료형의 이해
	bool isPos;					// bool이 기본자료형이므로 변수 선언시 사용이 가능하다.(함수가 받을 매개변수 또는 출력자료형으로도 사용가능)
	int num_2;
	cout << "Input number : ";
	cin >> num_2;

	isPos = IsPositive(num_2);

	if (isPos)
		cout << "Positive number" << endl;
	else
		cout << "Negative number" << endl;

	// * 출력결과 *
	// Input number : 12
	// Positive number

	
	return 0;

}