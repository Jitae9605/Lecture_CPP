#include <iostream>
using namespace std;

// 4.템플릿과 스태틱 
// 4_1.함수탬플릿과 static 지역변수
// 함수탬플릿 내부에 선언된 static은 템플릿함수별로 각각 선언된것이다

template <typename T>
void ShowStaticValue(void)
{
	static T num = 0;
	num += 1;
	cout << num << " ";
}

int main(void)
{
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	cout << endl;
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	cout << endl;
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();

	// * 출력결과 *
	// 1 2 3
	// 1 2 3
	// 1 2 3

	// num은 static인데 공유되지 못했다 -> 해당 템플릿 내서의 지역변수다.
	return 0;
}