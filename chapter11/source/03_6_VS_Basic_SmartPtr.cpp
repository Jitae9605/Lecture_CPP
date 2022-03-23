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
	// unique_ptr : 기본제공 스마트포인터
	/*unique_ptr<AAA> ptr1 = make_unique<AAA>();
	ptr1->func();*/

	cout << "----------------" << endl;

	// shared_ptr : 객체하나가 여러개의 포인터를 가질수 있음
	shared_ptr<AAA>ptr1 = make_shared<AAA>();			// <AAA> : 템플릿
	ptr1->func();

	cout << "count : " << ptr1.use_count() << endl;		// use_count : 포인터 갯수세는 것 
	{
		shared_ptr<AAA>ptr2(ptr1);
		cout << "count : " << ptr2.use_count() << endl;
		cout << "count : " << ptr1.use_count() << endl;
	}
	cout << "count : " << ptr1.use_count() << endl;

	// * 출력결과 *
	//

	return 0;
}