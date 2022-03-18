#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

// 유도클래스 == 상속받은 클래스

class SoBase
{
private:
	int baseNum;

public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << endl;
	}

	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}


	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;

public:
	SoDerived() : derivNum(30)
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) :derivNum(n)
	{
		cout << "SoDerived(int n)" << endl;
	}

	SoDerived(int n1, int n2) :SoBase(n1), derivNum(n2)
	{
		cout << "SoDerived(int n1, int n2)" << endl;
	}

	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}

	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main(void)
{
	cout << "case 1....." << endl;
	SoDerived dr1;
	dr1.ShowDerivData();
	cout << "-------------------------" << endl << endl;

	cout << "case 2....." << endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "-------------------------" << endl << endl;

	cout << "case 3....." << endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	cout << "-------------------------" << endl << endl;

	// * 출력결과 *
	// case 1.....
	// SoBase()
	// SoDerived()
	// 20
	// 30
	// ------------------------ -
	// 
	// case 2.....
	// SoBase()
	// SoDerived(int n)
	// 20
	// 12
	// ------------------------ -
	// 
	// case 3.....
	// SoBase(int n)
	// SoDerived(int n1, int n2)
	// 23
	// 24
	// ------------------------ -

	return 0;
}