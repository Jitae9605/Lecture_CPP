#include<iostream>
#pragma warning(disable:4996)
using namespace std;

// 1. 포인터 객체는 자료형이 부모객체일경우 상속받는 자식객체를 가리킬수 있다

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
	Person* ptr1 = new Student();				// Person 형 포인터 ptr1 이 Student를 가리킨다 ( Person이 부모객체 이므로 가능 )
	Person* ptr2 = new PartTimeStudent();		// Person 형 포인터 ptr2 이 PartTimeStudent를 가리킨다 ( Person이 부모객체(Student)의 부모객체이므로 가능 )
	Student* ptr3 = new PartTimeStudent();		// Student 형 포인터 ptr3 이 PartTimeStudent를 가리킨다 (Student가 부모객체 이므로 가능 )
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();

	delete ptr1;
	delete ptr2;
	delete ptr3;

	// * 출력결과 *
	// Sleep
	// Sleep
	// Study

	return 0;

}