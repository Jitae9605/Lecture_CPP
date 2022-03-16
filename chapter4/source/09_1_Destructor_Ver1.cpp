#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 9. �Ҹ���
// 

using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1; // �ι��ڸ� ����(+1)
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~Person()						// �Ҹ���
	{
		delete[]name;
		cout << "called destructor!" << endl;	// �̰� �������� ���� �Ҹ��ڸ� ����Ѱ� ��� �ڵ����� �Ҹ��ڰ� ����Ʈ�� ����! 
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();


	return 0;

	// * ��°�� *
	// �̸� : Lee dong woo
	// ����: 29
	// �̸� : Jang dong gun
	// ���� : 41
	// called destructor!
	// called destructor!
}