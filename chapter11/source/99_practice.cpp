#include<iostream>
#pragma warning(disable:4996)

using namespace std;

class AAA
{
public:
	AAA() {}
	~AAA() {}
	void func() {
		cout << "AAA::func()" << endl;
	}
};

int main()
{
	unique_ptr<AAA> ptr1 = make_unique<AAA>();

	return 0;
}