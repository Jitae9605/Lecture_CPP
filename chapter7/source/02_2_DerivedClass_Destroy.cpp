#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

// ����Ŭ������ �Ҹ��ڿ� �Ҹ���ȣ���� Ÿ�̹�

class SoBase
{
private:
	int baseNum;

public:
	

	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase() : " << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}

	
};

class SoDerived : public SoBase
{
private:
	int derivNum;

public:
	
	SoDerived(int n) :SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : "<< derivNum << endl;
	}


	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main(void)
{
	

	SoDerived drv1(15);
	SoDerived drv2(27);

	// * ��°�� *
	// SoBase() : 15
	// SoDerived() : 15
	// SoBase() : 27
	// SoDerived() : 27
	// ~SoDerived() : 27
	// ~SoBase() : 27
	// ~SoDerived() : 15
	// ~SoBase() : 15

	return 0;
}