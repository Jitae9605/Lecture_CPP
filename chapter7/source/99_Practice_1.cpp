// p296


#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

class MyFirendInfo
{
private:
	char* name;
	int age;

public:
	MyFirendInfo(const char* aname, int aage) :age(aage)
	{
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
	}

	void ShowMyFriendInfo()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFirendInfo
{
private:
	char* addr;
	char* phone;

public:
	MyFriendDetailInfo(const char* aaddr, const char* aphone, const char* aname, int aage)
		: MyFirendInfo(aname,aage)
	{
		addr = new char[strlen(aaddr) + 1];
		strcpy(addr, aaddr);
		phone = new char[strlen(aphone) + 1];
		strcpy(phone, aphone);
	}

	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소 : " << addr << endl;
		cout << "전화 : " << phone << endl;
	}

};

int main(void)
{
	MyFriendDetailInfo p1("부산", "010-1234-5678", "Lee", 28);
	p1.ShowMyFriendDetailInfo();

	return 0;
}