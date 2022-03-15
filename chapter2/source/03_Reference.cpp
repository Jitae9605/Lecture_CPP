#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3.참조자의 이해

// 4)
void SwapByRef2(int& ref1, int& ref2)		// 매개변수를 참조자로 받는다.
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

// 5)
int& RefRetFuncOne(int& ref);
int RefRetFuncTwo(int& ref);

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

	std::cout << "------------ < 3) 포인터 참조자  > ----------------" << std::endl;
	// 3) 포인터 참조자

	int num_3 = 12;
	int* ptr_3 = &num_3;
	int** dptr_3 = &ptr_3;

	int& ref_3 = num_3;				// int &ref_3		= num_3
	int* (&pref_3) = ptr_3;			// int *(&pref_3)	= *(ptr_3) = *&num_3 = num_3
	int** (&dpref_3) = dptr_3;		// int **(&dpref_3) = **(dptr_3) = (*(*&ptr_3)) = (*&(*&num_3)) = num_3

	cout << ref_3 << endl;			// num_3 = 12
	cout << *pref_3 << endl;		// *ptr_3 = *&num_3 = num_3 = 12
	cout << **dpref_3 << endl;		// **dptr = *(*&ptr_3) = *ptr_3 = *&num_3 = num_3 = 12

	// * 출력결과 *
	// 12
	// 12
	// 12

	std::cout << "------------ < 4) 참조자 활용  > ----------------" << std::endl;
	// 4) 참조자 활용
	// Call-by-reference 이다 
	int val1_4 = 10;
	int val2_4 = 20;

	SwapByRef2(val1_4, val2_4);				// 입력받은 매개변수의 참조자를 함수내부에 만들어 해당값을 교환
	cout << "val1_4 : " << val1_4 << endl;
	cout << "val2_4 : " << val2_4 << endl;

	// * 출력결과 *
	// val1_4 : 20
	// val2_4 : 10


	std::cout << "------------ < 5) 반환형이 참조자인 함수 > ----------------" << std::endl;
	// 5) 반환형이 참조자인 함수
	// 반환형이 참조자일경우 그 반환값을 받는 대상의 자료형에 따라 결과가 달라진다
	// 참조자가 그 값을 받을경우, 받는 참조자도 매개변수 등의 참조자가 된다.
	// 참조자가 아닐 경우, 받는 대상은 오로지 값만을 받는다.

	int num1_5 = 1;

	// 반환형이 참조자인 함수
	int& num2_5 = RefRetFuncOne(num1_5);					// 이러면 num1_5에 대한 참조자가 2개(num2_5, ref)가 생겼다가 함수를 빠져나오면서 1개(ref)가 소멸
	int num3_5 = RefRetFuncOne(num1_5);						// 이러면 num3_5변수에 함수의 반환하는 값만 저장된다(값 복사)	
															// 즉, num3_5는 완전히 별개의 다른 함수이다.
	
	// 반환형이 정수형인 함수
	//int& num4_5 = RefRetFuncTwo(num1_5);					// 참조자가 일반 반환값을 받을수 없다 
															// ( 오류발생!!! => 함수가 끝나면 값만 남고 변수가 사라지므로 참조자가 가리킬 대상이 없음)

	int num5_5 = RefRetFuncTwo(num1_5);						// 이건 그냥 변수가 값받는것

	num1_5++;
	num2_5++;
	num3_5 += 100;

	cout << "num1_5 : " << num1_5 << endl;
	cout << "num2_5 : " << num2_5 << endl;
	cout << "num3_5 : " << num3_5 << endl;				// num3_5가 별개의 함수임을 증명하기 위해 다른값을 더함
	//cout << "num4_5 : " << num2_5 << endl;			// 오류이므로 주석처리
	cout << "num5_5 : " << num2_5 << endl;				


	// * 출력결과 *
	// num1_5 : 4
	// num2_5 : 4
	// num3_5 : 103
	// num5_5 : 6			


	return 0;
}

// 5)
int& RefRetFuncOne(int& ref)
{
	ref++;
	return ref;
}

int RefRetFuncTwo(int& ref)
{
	ref++;
	return ref;
}