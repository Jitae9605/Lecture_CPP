#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// Has - A 관계를 통한 상속 - 2번 방법
// Police has a Gun

class Gun
{
private:
	int bullet;

public:
	Gun(int bnum) :bullet(bnum)		// 장전된 총알갯수
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
	int handcuffs;				// 소지한 수갑갯수
	Gun* pistol;				// 소유하고있는 권총
public:
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)			//  소지한 수갑갯수
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

	Police pman2(0, 3);			// 권총소유 X
	pman2.Shot();
	pman2.PutHandcuff();

	// * 출력결과 *
	// BBANG!
	// SNAP!
	// Hut BBANG!
	// SNAP!

	return 0;
}