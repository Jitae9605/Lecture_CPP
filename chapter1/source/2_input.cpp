#include<iostream>

// 2. 입력(std::cin >> 변수명)

int main(void)
{
	// 1) 단순입력받음
	int val1;
	std::cout << "첫번째 숫자입력: ";
	std::cin >> val1;					// std::cin을 이용해 입력받은값을 val1에 저장(이중꺽쇠 방향주의)

	int val2;
	std::cout << "두번째 숫자입력: ";
	std::cin >> val2;					// std::cin을 이용해 입력받은값을 val2에 저장(이중꺽쇠 방향주의)

	int result = val1 + val2;			
	std::cout << "덧셈결과: " << result << std::endl;

	// * 출력결과 *
	// 첫번째 숫자입력 : 10		
	// 두번째 숫자입력 : 20
	// 덧셈결과 : 30


	// 2) 응용
	int val1_2 = 0, val2_2 = 0;
	int result_2 = 0;

	std::cout << "두개의 숫자입력: ";
	std::cin >> val1 >> val2;

	if (val1_2 < val2_2)
	{
		for (int i = val1_2 + 1; i < val2_2; i++)
		{
			result_2 += i;
		}
	}
	else
	{
		for (int i = val2_2 + 1; i < val1_2; i++)
		{
			result_2 += i;
		}

		std::cout << "두 수사이의 정수 합: " << result_2 << std::endl;
	}


	return 0;
}