#include<iostream>
#include<cstring>
#include<string>
#pragma warning(disable:4996)
using namespace	std;

int main(void)
{
	string str1 = "I ike ";
	string str2 = "string class";
	string str3 = str1 + str2;
	string str5 = "Good mornig!";

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str5.at(5) << endl;			// 6번째 문자 출력	[ = at(0) ~ at(n-1)		]
	cout << str5.front()<< endl;		// 맨앞 문자 출력		[ = at(0)				]
	cout << str5.back() << endl;		// 맨뒤 문자 출력		[ = at(n-1)				]
	cout << str5.size() << endl;		// 문자열 크기(변수 갯수)
	cout << str5.capacity() << endl;	// size + 널문자공간 + 여유공간

	str1 += str2;
	if (str1 == str2)
		cout << "동일한 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	string str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;

	// * 출력결과 *
	// I ike
	// string class
	// I ike string class
	// m
	// G
	// !
	// 동일하지 않은 문자열!
	// 문자열 입력 : Hi~
	// 입력한 문자열 : Hi~
	// 12
	// 15
	 

	return 0;
}
