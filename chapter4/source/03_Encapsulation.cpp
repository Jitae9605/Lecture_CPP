#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class SinivelCap
{
public:
	void Take() const
	{
		cout << "Äà¹°ÀÌ ³´½À´Ï´Ù" << endl;
	}
};

class SneezeCap
{
public:
	void Take() const
	{
		cout << "ÀçÃ¤±â°¡ ³´½À´Ï´Ù" << endl;
	}
};

class SnuffleCap
{
public:
	void Take() const
	{
		cout << "ÄÚ¸·ÈûÀÌ ³´½À´Ï´Ù" << endl;
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

	// * Ãâ·Â°á°ú *
	// Äà¹°ÀÌ ³´½À´Ï´Ù
	// ÀçÃ¤±â°¡ ³´½À´Ï´Ù
	// ÄÚ¸·ÈûÀÌ ³´½À´Ï´Ù

	return 0;
}