#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// * �̵�������
//	��������ڴ� ��ü�� ����� �ӽð�ü�� �����(������ ȣ��, ���ҳ����� �Ҹ��� ȣ��) ������ ����� �����Ѵ� 
//	��, �ܰ谡 ���� ������
// 
//	�̿�����, �̵������ڴ� ��ü�� ��������� �̵������ �Ǵ� ��ü�� ������� ��ü�� ����Ű�� �ϴ� �� �̴�.

class Human
{
private:
	char name[20];
	int age;
public:
	Human(const char* aname, int aage) : age(aage)		// ������
	{
		cout << "������ȣ��" << endl;
		strcpy(name, aname);
		
	}

	Human(const Human& other)	// lvalue ����						// ���������
	{
		cout << "���� ������ ȣ��" << endl;
		strcpy(name, other.name);
		age = other.age;
	}

	Human(Human&& other)		// rvalue ����						// �̵�������
	{
		cout << "�̵� ������ ȣ��" << endl;
		strcpy(name, other.name);
		age = other.age;
	}

	void viewHuman()
	{
		cout << "�̸� : " << name << ", " << "���� : " << age << endl << endl;
	}
	
};

int main()
{
	Human h1("ȫ�浿", 15);
	h1.viewHuman();

	Human h2(h1);				
	h2.viewHuman();

	Human h3(move(h1));			// �Ű������� rvalue�� �ٲ۴�
	h3.viewHuman();
	h1.viewHuman();


	

	return 0;
}