#include<iostream>
#pragma warning(disable:4996)
using namespace std;

// 1. ������ ��ü�� �ڷ����� �θ�ü�ϰ�� ��ӹ޴� �ڽİ�ü�� ����ų�� �ִ�

class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student :public Person
{
public:
	void Study() { cout << "Study" << endl; }
};

class PartTimeStudent :public Student
{
public:
	void work() { cout << "Work" << endl; }
};

int main(void)
{
	Person* ptr1 = new Student();				// Person �� ������ ptr1 �� Student�� ����Ų�� ( Person�� �θ�ü �̹Ƿ� ���� )
	Person* ptr2 = new PartTimeStudent();		// Person �� ������ ptr2 �� PartTimeStudent�� ����Ų�� ( Person�� �θ�ü(Student)�� �θ�ü�̹Ƿ� ���� )
	Student* ptr3 = new PartTimeStudent();		// Student �� ������ ptr3 �� PartTimeStudent�� ����Ų�� (Student�� �θ�ü �̹Ƿ� ���� )
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();

	delete ptr1;
	delete ptr2;
	delete ptr3;

	// * ��°�� *
	// Sleep
	// Sleep
	// Study

	return 0;

}