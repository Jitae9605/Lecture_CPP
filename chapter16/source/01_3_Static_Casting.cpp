#include<iostream>
using namespace std;

// 1_3.����ƽ ĳ����
// static_casting =  ��Ӱ��迡�� �������� ����ȯ
//  -> ����/���� Ŭ������ ������ �� ������ �����͸� �ƹ����Ǿ��� ����ȯ������(����! - å���� ���α׷����� ��)

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
	Car* pcar1 = new Truck(80, 200);					
	Truck* ptruck1 = static_cast<Truck*>(pcar1);		// ������ OK!
	ptruck1->ShowTruckState();

	cout << endl;

	Car* pcar2 = new Car(120);							
	Truck* ptruck2 = static_cast<Truck*>(pcar2);		// ������ OK! ������ weight���� ������ �����Ⱚ�� ���
	ptruck2->ShowTruckState();

	return 0;
}
