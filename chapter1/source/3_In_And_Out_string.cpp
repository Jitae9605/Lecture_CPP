#include <iostream>

// 3. 문자열의 입출력

int main(void)
{
	// 1)문자열의 입력과 출력

	char name[100];						// 문자열 선언
	char lang[200];						// 문자열 선언

	std::cout << "이름은 무엇입니까? ";
	std::cin >> name;					

	std::cout << "좋아하는 프로그래밍 언어는 무엇인가요?";	
	std::cin >> lang;					

	std::cout << "내 이름은 " << name << "입니다.\n";		// 여전히 '\n'는 개행문자의 역할
	std::cout << "내가 제일 좋아하는 프로그래밍 언어는 " << lang << "입니다." << std::endl;

	// * 출력결과 * 
	// 이름은 무엇입니까 ? YOON
	// 좋아하는 프로그래밍 언어는 무엇인가요 ? C++
	// 내 이름은 YOON입니다.
	// 내가 제일 좋아하는 프로그래밍 언어는 C++입니다.


	return 0;
}