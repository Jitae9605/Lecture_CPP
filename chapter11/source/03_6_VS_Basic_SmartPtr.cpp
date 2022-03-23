#include<iostream>
#pragma warning(disable:4996)

using namespace std;

class AAA
{
public:
	AAA() {
		cout << "AAA()" << endl;
	}
	~AAA() {
		cout << "~AAA()" << endl;
	}
	void func() {
		cout << "AAA::func()" << endl;
	}
};

int main()
{
	// unique_ptr : �⺻���� ����Ʈ������
	/*unique_ptr<AAA> ptr1 = make_unique<AAA>();
	ptr1->func();*/

	cout << "----------------" << endl;

	// shared_ptr : ��ü�ϳ��� �������� �����͸� ������ ����
	shared_ptr<AAA>ptr1 = make_shared<AAA>();			// <AAA> : ���ø�
	ptr1->func();

	cout << "count : " << ptr1.use_count() << endl;		// use_count : ������ �������� �� 
	{
		shared_ptr<AAA>ptr2(ptr1);
		cout << "count : " << ptr2.use_count() << endl;
		cout << "count : " << ptr1.use_count() << endl;
	}
	cout << "count : " << ptr1.use_count() << endl;

	// * ��°�� *
	//

	return 0;
}