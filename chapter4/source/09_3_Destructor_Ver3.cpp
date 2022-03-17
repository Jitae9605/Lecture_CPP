#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 09_2_Destructor_Ver2�� ��ü�迭�� ��ü�����͹迭�� �ٲ�
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
	Person* parr[3];						// ��ü�迭����
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;
		parr[i] = new Person(namestr, age);  // SetPersonInfo(char* myname, int myage)
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0];
	delete parr[1];
	delete parr[2];





	return 0;

	// * ��°�� *
	// �̸� : �ȼ���
	// ����: 31
	// �̸� : ���ѿ�
	// ���� : 39
	// �̸� : ������
	// ���� : 19
	// �̸� : �ȼ���, ���� : 31
	// �̸� : ���ѿ�, ���� : 39
	// �̸� : ������, ���� : 19
	// called destructor!
	// called destructor!
	// called destructor!