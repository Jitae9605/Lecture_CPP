#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3. 증상별 감기약 처방

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

	// * 출력결과 *
	// 콧물이 낫습니다
	// 재채기가 낫습니다
	// 코막힘이 낫습니다

	return 0;
}