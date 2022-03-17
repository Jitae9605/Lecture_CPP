#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 10. this�������� ���ؿ� ���
// this�� ��ü�ڽ��� ����Ű�� �뵵�� ���Ǵ� ������

using namespace std;

// 1)
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num = " << num<<", ";
		cout << "address = " << this << endl;			// ������ȣ��� ���ÿ� ������ ��ü�� �ּҰ��� ����Ѵ�.
	}

	void ShowSimpleData()
	{
		cout << num << endl;
	}

	SoSimple* GetThisPointer()
	{
		return this;
	}

};

// 2)
class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)		// ���� ������ ������ �ȵǴµ� c++�� this�� ������ �־� �̸� ������ش�.
	{
		this->num1 = num1;				// �̷��� ������ �����ϹǷ�
		this->num2 = num2;				// �ٵ� ���� ���� ���� �����.
	}
	
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void)
{
	std::cout << "------------ < 1) this�������� ���ؿ� ��� > ----------------" << std::endl;
	// 1) this�������� ���ؿ� ���
	SoSimple sim1(100);							// ������ȣ�� - ���ÿ� ���������(= 100), �ּҰ�(= this ��)�� ��µ�
	SoSimple* ptr1 = sim1.GetThisPointer();		// ptr1�� this�� �̿��� ��ü�� �ּҰ��� ����
	cout << ptr1 << ", ";						// ptr1 ���
	ptr1->ShowSimpleData();

	SoSimple sim2(200);							// ������ȣ�� - ���ÿ� ���������(= 200), �ּҰ�(= this ��)�� ��µ�
	SoSimple* ptr2 = sim2.GetThisPointer();		// ptr2�� this�� �̿��� ��ü�� �ּҰ��� ����
	cout << ptr2 << ", ";						// ptr2 ���
	ptr2->ShowSimpleData();	

	// * ��°�� *
	// num = 100, address = 008FF9A4
	// 008FF9A4, 100
	// num = 200, address = 008FF98C
	// 008FF98C, 200

	std::cout << "------------ < 2) this �������� ���뼺 > ----------------" << std::endl;
	// 2) this �������� ���뼺
	TwoNumber two(2, 4);
	two.ShowTwoNumber();

	// * ��°�� *
	// 2
	// 4

	return 0;
}

	
