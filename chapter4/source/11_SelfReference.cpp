#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 12. selfreference�� ��ȯ
// Ŭ�����Լ��� ��ȯ���� �ڱ����������·� �ϰ� ��ȯ�ϴ� return�� ������ �ּҰ�����(*this) �Ѵ�.

using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "��ü����" << endl;
	}
	SelfRef& Adder(int n)			// ������ �����Ҽ� �ִ� ��������(*this)�� ��ȯ��
	{
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return*this;
	}
};

int main(void)
{
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);		// obj�� num(= 3)�� 2�� ����(by Adder(2)) =>	obj�� num = 5

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	// �ڱ������� ���п� �̷��� ����
	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();	// obj�� num(= 5)�� 1�� ���ϰ�(by Adder(1))	=> obj�� num = 6
															// 2�� ����(by Adder(2))						=> obj�� num = 8

	// * ��°�� *
	// ��ü����
	// 5
	// 5
	// 6
	// 8
	
	return 0;
}