#include<iostream>
using namespace std;

// 3_3 스택풀기
// 스택풀기 = 예외가 처리되지않아서 함수를 호출한 영역으로 예외데이터가 전달되는 현상
// 이런 이름이 붙은 이유를 알아보자

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "예외코드 : " << expn << endl;
	}


	// * 출력결과 *
	// SiompleFuncOne(void)
	// SiompleFuncTwo(void)
	// SimpleFuncThree(void)
	// 예외코드 : -1

	// 각 함수 아래부분의 end구문ㄷㄹ이 실행되지 않는다 
	// -> 예외가 발생하자마자 뒤에껄 전부 무시하고 throw로 값을 바로 catch에게 던진다

	return 0;

	
}

void SimpleFuncOne(void)
{
	cout << "SiompleFuncOne(void)" << endl;
	SimpleFuncTwo();
	cout << "SimpleFuncOne end" << endl;
}

void SimpleFuncTwo(void)
{
	cout << "SiompleFuncTwo(void)" << endl;
	SimpleFuncThree();
	cout << "SimpleFuncTwo end" << endl;
}

void SimpleFuncThree(void)
{
	cout << "SimpleFuncThree(void)" << endl;
	throw - 1;
}

