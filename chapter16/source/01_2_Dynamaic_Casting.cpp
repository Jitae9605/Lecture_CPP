#include<iostream>
using namespace std;

// 1_2.���̳��� ĳ����
// dynamic_casting =  ��Ӱ��迡�� ������ ����ȯ
//  -> ��Ӱ��迡 �ִ� ����Ŭ������ ������ �� ������ �����͸� ����Ŭ������ ������ �� ������ �����ͷ� ����ȯ �Ѵٴ� �ǹ�


class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) :fuelGauge(fuel)
	{ }
	void ShowCarState() { cout << "�ܿ� ���ᷮ : " << fuelGauge << endl; }
};

class Truck : public Car
{
private:
	int freighWeight;
public:
	Truck(int fuel, int weight) :Car(fuel), freighWeight(weight)
	{ }

	void ShowTruckState()
	{
		ShowCarState();
		cout << "ȭ���� ���� : " << freighWeight << endl;
	}
};

int main(void)
{
	// Car* pcar1 = new Truck(80, 200);
	// Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);		// ������ ����!

	// Car* pcar2 = new Car(120);
	// Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);		// ������ ����!

	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Truck*>(ptruck3);				// ������ OK!


	return 0;
}
