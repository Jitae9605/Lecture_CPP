#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 4. 종합감기약

class SinivelCap
{
public:
	void Take() const
	{
		cout << "콧물이 낫습니다" << endl;
	}
};

class SneezeCap
{
public:
	void Take() const
	{
		cout << "재채기가 낫습니다" << endl;
	}
};

class SnuffleCap
{
public:
	void Take() const
	{
		cout << "코막힘이 낫습니다" << endl;
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

	// * 출력결과 *
	// 콧물이 낫습니다
	// 재채기가 낫습니다
	// 코막힘이 낫습니다

	return 0;
}