#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 2_1 ��������
// ����� ����� ����Ǵ� ����
// ��������� ���� �޸𸮰����� �����ϴ°�� ������ �߻��� �� �ִ�(�����Ҵ�, �����͸� �̿��ϴ� ��� �߻�)

using namespace std;

// 1)
class Person
{
private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];					// ������ ����
		strcpy(name, myname);
		age = myage;

	}

	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
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
	std::cout << "------------ < 1) ���������� ���輺 > ----------------" << std::endl;
	// 1) ���������� ���輺 
	Person man1("Lee dong woo", 29);
	Person man2 = man1;					// ��������
	man1.ShowPersonInfo();
	//man2.ShowPersonInfo();


	// * ��°�� *
	// �̸�: Lee dong woo
	// ���� : 29
	// �̸� : Lee dong woo
	// ���� : 29
	// called destructor!
	
	//  - �����߻� - ( called destructor! �� 2�� ��µǾ��ϴµ� 1���� ���� �����޼����� ��µ� )
	// char* name�� "Lee dong woo"�� �����ּҸ� �������̹Ƿ� delete�� ���� man1�� ������� 
	// �� �ּҸ� �����ذ� man2�� man1�� delete�ɶ� �̹� �����Ȱ� ����� �ּ�(����)�� �ٽ� �����ϰ��� �ϹǷ� �����߻�
	


	return 0;
}

