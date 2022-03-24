#include<iostream>
using namespace std;

// 1_4 함수템플릿의 특수화의 필요성

template <typename T>		// 함수템플릿
T Max(T a, T b)		// 여기서 T는 임의의 자료형이다 나중에 우리가 지정
{
	return a > b ? a : b;
}

template <>
char* Max(char* a, char* b)
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;	
	return strlen(a) > strlen(b) ? a : b;					// 문자열 길이비교
}

template <>
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;						// 사전순 비교
}


int main(void)
{
	cout << Max(11, 15)						<< endl;
	cout << Max('T', 'Q')					<< endl;
	cout << Max(3.5, 7.5)					<< endl;
	cout << Max("Simple", "Best")			<< endl;

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2)					<< endl;


	// * 출력결과 *
	// 15
	// T
	// 7.5
	// const char* Max<const char*>(const char* a, const char* b)
	// Simple
	// char* Max<char*>(char* a, char* b)
	// Simple

	return 0;

}

