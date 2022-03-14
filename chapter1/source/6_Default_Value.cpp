#include <iostream>

//6. 함수의 매개변수에 디폴트값 설정
// C++은 함수의 매개변수에 디폴트값을 설정할수 있다.
// (함수호출시 인자를 전달하지 않으면 자동 입력될 값)
// 디폴트값은 선언부분에만 표현해도 된다

// 1) 함수
int Adder(int num1 = 1, int num2 = 2);		// 선언에서 매개변수 디폴트값을 선언

// 2)함수
int BoxVolume(int length, int width = 1, int height = 1);

int main(void)
{
	std::cout << "------------ < 1) 디폴트값 설정  > ----------------" << std::endl;
	// 1) 디폴트값 설정 
	std::cout << Adder() << std::endl;		// 함수에 매개변수 안줌 -> 디폴트값이 입력됨 => (Adder(1,2) = 3)
	std::cout << Adder(5) << std::endl;		// 함수에 매개변수 1개만 줌 -> num2에 디폴트값입력됨 => (Adder(5,2) = 7)
	std::cout << Adder(3,5) << std::endl;	// 함수에 매개변수 2개모두 줌 => (Adder(3,5) = 8)
	
	// * 출력결과 *
	// 3
	// 7
	// 8

	std::cout << "------------ < 2) 부분적디폴트 값 설정  > ----------------" << std::endl;
	// 2) 부분적디폴트 값 설정
	// 디폴트값은 부분적 줄수 있다
	std::cout << "[3,3,3] : " << BoxVolume(3, 3, 3) << std::endl;		// 3 * 3 * 3
	std::cout << "[5,5,D] : " << BoxVolume(5,5) << std::endl;			// 5 * 5 * 1
	std::cout << "[7,D,D] : " << BoxVolume(7) << std::endl;				// 7 * 1 * 1
	//std::cout << "[D,D,D] : " << BoxVolume() << std::endl;			// ? * 1 * 1  -> 오류발생(length에는 디폴트값없음)
	//std::cout << "[5,D,5] : " << BoxVolume(5, , 5) << std::endl;		// 5 * 5 * 1  -> 오류발생(비울수 없음)
	
	// * 출력결과 *
	// [3, 3, 3] : 27
	// [5, 5, D] : 25
	// [7, D, D] : 7


	return 0;
}


// 1)함수
int Adder(int num1, int num2)				// 정의부분에서는 안해도된다.
{
	return num1 + num2;
}

// 2)함수
int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}