#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// Has - A ���踦 ���� ��� - 2�� ���
// Police has a Gun

class Gun
{
private:
	int bullet;

public:
	Gun(int bnum) :bullet(bnum)		// ������ �Ѿ˰���
	{ }

	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;				// ������ ��������
	Gun* pistol;				// �����ϰ��ִ� ����
public:
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)			//  ������ ��������
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}

	void Shot()
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}

	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}

};

int main(void)
{
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3);			// ���Ѽ��� X
	pman2.Shot();
	pman2.PutHandcuff();

	// * ��°�� *
	// BBANG!
	// SNAP!
	// Hut BBANG!
	// SNAP!

	return 0;
}