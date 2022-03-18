#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 1_2. Const �Լ� �����ε�
// 

using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n)
	{ }

	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void SimpleFunc() 
	{
		cout << "SimpleFunc : " << num << endl;
	}

	void SimpleFunc() const
	{
		cout << "const SimpleFunc : " << num << endl;
	}
};

void YourFunc(const SoSimple &obj)
{
	obj.SimpleFunc();
}

int main()
{
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();			// �ڵ����� const�� ����

	YourFunc(obj1);				// obj1�� const SoSimple &obj �� �Ű������� ���鼭 const �Լ��� �Ǿ� const �Լ��� ������
	YourFunc(obj2);				

	// *��°�� *
	// SimpleFunc : 2
	// const SimpleFunc : 7
	// const SimpleFunc : 2
	// const SimpleFunc : 7


	return 0;
}