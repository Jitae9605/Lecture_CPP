#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// Has - A ���踦 ���� ��� - 1�� ���
// Police has a Gun

class Gun
{
private:
	int bullet;

public:
	Gun(int bnum):bullet(bnum)		// ������ �Ѿ˰���
	{ }

	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police : public Gun
{
private:
	int handcuffs;
public:
	Police(int bnum,int bcuff)
		:Gun(bnum),handcuffs(bcuff)			// ������ �Ѿ˰���, ������ ��������
	{ }

	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
};

int main(void)
{
	Police pman(5, 3);
	pman.Shot();
	pman.PutHandcuff();

	// * ��°�� *
	// BBANG!
	// SNAP!

	return 0;
}