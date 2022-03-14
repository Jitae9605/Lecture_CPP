#include <iostream>

// 1. 복습 및 중요포인트

int main(void)
{
	// 1) const와 포인터
	int val1, val2, val3;

	const int num = 10;						// 변수 num의 상수하 
	const int* ptr1 = &val1;				// 포인터 ptr1에 의한 val1의 값 변경불가
	int * const ptr2 = &val2;				// 포인터 ptr2의 상수화
	const int* const ptr3 = &val3;			// 포인터 ptr3의 상수화 및 ptr3에 의한 val3의 값 변경불가

	// 2) 데이터, 스택, 힙

	// 데이터(Data)		= 전역변수가 저장되는 영역
	// 스택(stack)		= 지역변수 및 매개변수가 저장되는 영역
	// 힙(Heap)			= malloc 함수 호출에 의해 프로그램이 실행되는 과정에서 동적으로 할당이 이뤄지는 영역


	// 3) Call-by-value / Call-by-reference

	/*
	
	void SwapByValue(int num1,int num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
		// Call-by-value
	}

	Void SwapByRef(int*ptr1,int*ptr2)
	{
		int temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
		// Call-by-reference
	}

	*/
	return 0;
}