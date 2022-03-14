#include<iostream>

// 4.예제1번
// 5개의 정수를 입력받아 합계를 계산해  출력하는 프로그램

int main(void)
{
	int a[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i+1 << "번째 정수 입력 : ";
		std::cin >> a[i];
		sum += a[i];
	}

	std::cout << "합계 : " << sum<<std::endl;
	
	// * 출력결과 *
	// 1번째 정수 입력 : 1
	// 2번째 정수 입력 : 2
	// 3번째 정수 입력 : 3
	// 4번째 정수 입력 : 4
	// 5번째 정수 입력 : 5
	// 합계 : 15

	return 0;
}