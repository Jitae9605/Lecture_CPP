#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 4. ���հ����

class SinivelCap
{
public:
	void Take() const
	{
		cout << "�๰�� �����ϴ�" << endl;
	}
};

class SneezeCap
{
public:
	void Take() const
	{
		cout << "��ä�Ⱑ �����ϴ�" << endl;
	}
};

class SnuffleCap
{
public:
	void Take() const
	{
		cout << "�ڸ����� �����ϴ�" << endl;
	}
};

class Contac600
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;
public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient
{
public:
	void TakeContac600(const Contac600& cap)const
	{
		cap.Take();
	}
};

int main(void)
{
	Contac600 cap;

	ColdPatient sufferer;
	sufferer.TakeContac600(cap);

	// * ��°�� *
	// �๰�� �����ϴ�
	// ��ä�Ⱑ �����ϴ�
	// �ڸ����� �����ϴ�

	return 0;
}