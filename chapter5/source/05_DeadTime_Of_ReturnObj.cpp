#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 6. ��ȯ��ü�� �Ҹ����
// 

using namespace std;

class Sosimple
{
private:
	int num;

public:
	Sosimple(int n) :num(n)
	{
		cout << "New Object : " << this << endl;
	}

	Sosimple(const Sosimple& copy) :num(copy.num)		// ����������� ����Ʈ - ���� ��޾��ص� ��������(�������� �Ⱥ��ϻ�)
	{
		cout << "New Copy Object : " << this << endl;
	}

	~Sosimple()
	{
		cout << "Destroy Object : " << this << endl;
	}
};

Sosimple simplefuncobj(Sosimple ob)
{
	cout << "Parm ADR : " << &ob<<endl;
	return ob;							// �ӽð�ü
}

int main(void)
{
	Sosimple obj(7);
	simplefuncobj(obj);
	
	cout << endl;

	Sosimple tempRef = simplefuncobj(obj);
	cout << "Return Obj" << &tempRef << endl;

	// * ��°�� *
	// New Object : 0053F8EC			// 40�� : obj����
	// New Copy Object : 0053F7D4		// 32���� �Լ�ȣ��� �Ű����� ob����
	// Parm ADR : 0053F7D4				// �Լ� ���� ��¹�(ob�� �ּҰ�)
	// New Copy Object : 0053F808		// return ob ��ȯ�� ���� �ӽð�ü����
	// Destroy Object : 0053F7D4		// �Ű����� ob�Ҹ�
	// Destroy Object : 0053F808		// ��ȯ�� ���� ������ �ӽð�ü �Ҹ�
	// 
	// New Copy Object : 0053F7D4		// �Լ�ȣ��� �Ű����� ob����
	// Parm ADR : 0053F7D4				// �Լ����� ��¹�(ob�� �ּҰ�)
	// New Copy Object : 0053F8E0		// return ob ��ȯ�� ���� �ӽð�ü ����
	// Destroy Object : 0053F7D4		// �Ű����� ob�Ҹ�
	// Return Obj0053F8E0				// tempRef�� �ּҰ��� ��ȯ������ �ӽð�ü�� ���� == ��ȯ�� ���� �ӽð�ü�� �ּҰ��� tempRef�� ������(��, �����ϰ�����)
	// Destroy Object : 0053F8E0		// tempRef�� �����ϴ� �ӽð�ü �Ҹ� ( => tempRef �� �Ҹ�� �Ͱ� ���� )
	// Destroy Object : 0053F8EC		// obj�Ҹ�

	// !!! ���� !!!
	// �����δ� tempRef�� �����Ǵ°� �ƴ϶� ��ȯ�� ���� ������ �ӽð�ü�� tempRef�� �̸��� �Ҵ��� �� !!!
	return 0;
}