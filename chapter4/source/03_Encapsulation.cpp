#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3. ?????? ?????? ó??

class SinivelCap
{
public:
	void Take() const
	{
		cout << "?๰?? ?????ϴ?" << endl;
	}
};

class SneezeCap
{
public:
	void Take() const
	{
		cout << "??ä?Ⱑ ?????ϴ?" << endl;
	}
};

class SnuffleCap
{
public:
	void Take() const
	{
		cout << "?ڸ????? ?????ϴ?" << endl;
	}
};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap& cap)const
	{
		cap.Take();
	}
	void TakeSneezeCap(const SneezeCap& cap)const
	{
		cap.Take();
	}
	void TakeSnuffleCap(const SnuffleCap& cap)const
	{
		cap.Take();
	}
};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);

	// * ???°??? *
	// ?๰?? ?????ϴ?
	// ??ä?Ⱑ ?????ϴ?
	// ?ڸ????? ?????ϴ?

	return 0;
}