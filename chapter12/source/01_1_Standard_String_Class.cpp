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
	cout << str5.at(5) << endl;			// 6��° ���� ���	[ = at(0) ~ at(n-1)		]
	cout << str5.front()<< endl;		// �Ǿ� ���� ���		[ = at(0)				]
	cout << str5.back() << endl;		// �ǵ� ���� ���		[ = at(n-1)				]
	cout << str5.size() << endl;		// ���ڿ� ũ��(���� ����)
	cout << str5.capacity() << endl;	// size + �ι��ڰ��� + ��������

	str1 += str2;
	if (str1 == str2)
		cout << "������ ���ڿ�!" << endl;
	else
		cout << "�������� ���� ���ڿ�!" << endl;

	string str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;

	// * ��°�� *
	// I ike
	// string class
	// I ike string class
	// m
	// G
	// !
	// �������� ���� ���ڿ�!
	// ���ڿ� �Է� : Hi~
	// �Է��� ���ڿ� : Hi~
	// 12
	// 15
	 

	return 0;
}
