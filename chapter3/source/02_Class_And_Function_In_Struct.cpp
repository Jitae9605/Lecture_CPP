#include <iostream>
#include <string.h>

// 2.����ü ���ο� �Լ� ����

#pragma warning(disable:4996)
using namespace std;

//1)
typedef struct human
{
	char name[20];
	int age;
	char job[10];

	void showdata(void)
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << "��" << endl;
		cout << "���� : " << job << endl << endl;
	}

}Human;

// 2)
class human_class	// ����, ĸ��ȭ - ����Լ��� ���ؼ��� ���� �Է�/����/���� ���� ������
{
	char name[20];					// private
	int age;						// private
	char job[10];					// private
	

	// ������ = �ʱ�ȭ��Ű�� �������(������������)
	/*human_class (char* a, int b, char* c)
	{
		name = a;
		age = b;
		job = c;
	}*/

	// class �����Լ�
	void showdata(void)				// public
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << "��" << endl;
		cout << "���� : " << job << endl << endl;
	}

};

int main(void)
{
	std::cout << "------------ < 1) ����ü ���ο� �Լ����� �� ���  > ----------------" << std::endl;
	// 1) ����ü ���ο� �Լ����� �� ���
	Human h1 = { "ȫ�浿", 20, "�л�" };
	h1.showdata();

	// * ��°�� *
	// �̸� : ȫ�浿
	// ���� : 20��
	// ���� : �л�


	std::cout << "------------ < 2) Ŭ������ ���� ����ü���� ������  > ----------------" << std::endl;
	// 2) Ŭ������ ���� ����ü���� ������
	human_class h1();

	return 0;
}