#include<iostream>

// 7.인라인함수
// 매크로함수를 좀더 편하게 사용하기위한 함수

// 1) 매크로 함수
#define SQUARE(x) ((x)*(x))		// 매크로함수 (아예 대체하는것 즉, 전처리의 영역이다 = 전처리기가 즉시연산)

// 2) 인라인 함수
inline int SQUARE_inline(int x)
{
	return x * x;
}

int main(void)
{
	std::cout << "------------ < 1) 매크로 함수  > ----------------" << std::endl;
	// 1) 매크로 함수
	std::cout << SQUARE(5) << std::endl; // == std::cout << ((5)*(5)) << std::endl;

	// * 출력결과 *
	// 25

	std::cout << "------------ < 2) 인라인 함수  > ----------------" << std::endl;
	// 2) 인라인함수
	// 인라인함수는 컴파일러가 우선 처리해서 매우 빠른 속도의 연산및 처리가 가능하다
	// 단 정의등이 매우 복잡하고 그에따라 활용이 제한적이다.

	std::cout << SQUARE_inline(5) << std::endl; // == std::cout << (5*5) << std::endl;
	std::cout << SQUARE_inline(12) << std::endl; // == std::cout << (12*12) << std::endl;

	// * 출력결과 *
	// 25
	// 144

	return 0;
}
