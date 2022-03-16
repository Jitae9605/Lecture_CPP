#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 09_1_Destructor_Ver1���� ��ü�迭�� �߰���
// 

using namespace std;

class Person
{
private:
	char* name;
	int age;

public:
	Person()		// ��ü�迭�� �̿��ϸ� ���ڸ� �ټ� ���⿡ �ݵ�� ������ ����Ʈ�� �����ؾ� �ʱ�ȭ��ų�� �ִ�.	
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char* myname, int myage)		// ��ü�迭 ������ ����� ������ ��������
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << ", ";
		cout << "���� : " << age << endl;
	}

	~Person()						
	{
		delete[]name;
		cout << "called destructor!" << endl;	 
	}
};

int main(void)
{
	Person parr[3];						// ��ü�迭����
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];					// strptr�� �����Ҵ�
		strcpy(strptr, namestr);				// �Է¹��� ���� �����Ҵ����� ����
		parr[i].SetPersonInfo(strptr, age);		// SetPersonInfo(char* myname, int myage)
	}

	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	
	


	return 0;

	// * ��°�� *
	// called Person()
	// called Person()
	// called Person()
	// �̸� : ������
	// ���� : 21
	// �̸� : ������
	// ���� : 31
	// �̸� : ���ѿ�
	// ���� : 34
	// �̸� : ������, ���� : 21
	// �̸� : ������, ���� : 31
	// �̸� : ���ѿ�, ���� : 34
	// called destructor!
	// called destructor!
	// called destructor!
}