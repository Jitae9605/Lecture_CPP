#include<iostream>
using namespace std;

// 1.c++������ ����ȯ����
// ����ȯ�� �߸��ǵ� �����Ϸ��� �̰� �ǵ��Ѱ����� �Ǽ����� �˼�����

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel):fuelGauge(fuel)
	{ }
	void ShowCarState() { cout << "�ܿ� ���ᷮ : " << fuelGauge << endl; }
};

class Truck : public Car
{
private:
	int freighWeight;
public:
	Truck(int fuel,int weight):Car(fuel),freighWeight(weight)
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
	Truck* ptruck1 = (Truck*)pcar1;		// ��������̴� ����ȯ - �����δ� �̷����ϸ� ���� �����߻�����
	ptruck1->ShowTruckState();

	cout << endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = (Truck*)pcar2;		// ������ ������ ����ȯ
	ptruck2->ShowTruckState();

	return 0;
}
