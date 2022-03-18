#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

// ªÛº”¿« ¡ﬂ√∏

class Car
{
private:
	int gasolineGauge;
	
public:
	Car(int n) : gasolineGauge(n)
	{ }

	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;

public:
	HybridCar(int n1, int n2) : Car(n1), electricGauge(n2)
	{ }

	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;

public:
	HybridWaterCar(int n1,int n2, int n3) : HybridCar(n1, n2), waterGauge(n3)
	{ }

	void ShowCurrentGauge()
	{
		cout << "¿‹ø© ∞°º÷∏∞ : " << GetGasGauge() << endl;
		cout << "¿‹ø© ¿¸±‚∑Æ : " << GetElecGauge() << endl;
		cout << "¿‹ø© øˆ≈Õ∑Æ : " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar h3(20, 30, 40);
	h3.ShowCurrentGauge();

	return 0;
}