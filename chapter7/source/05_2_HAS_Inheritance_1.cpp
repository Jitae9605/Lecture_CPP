#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// Has - A 관계를 통한 상속 - 1번 방법
// Police has a Gun

class Gun
{
private:
	int bullet;

public:
	Gun(int bnum):bullet(bnum)		// 장전된 총알갯수
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
		:Gun(bnum),handcuffs(bcuff)			// 장전된 총알갯수, 소지한 수갑갯수
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

	// * 출력결과 *
	// BBANG!
	// SNAP!

	return 0;
}