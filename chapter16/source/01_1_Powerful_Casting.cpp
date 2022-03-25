#include<iostream>
using namespace std;

// 1.c++에서의 현변환연산
// 형변환이 잘못되도 컴파일러는 이게 의도한것인지 실수인지 알수없다

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel):fuelGauge(fuel)
	{ }
	void ShowCarState() { cout << "잔여 연료량 : " << fuelGauge << endl; }
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
		cout << "화물의 무게 : " << freighWeight << endl;
	}
};

int main(void)
{
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = (Truck*)pcar1;		// 문제없어보이는 형변환 - 실제로는 이렇게하면 향후 문제발생가능
	ptruck1->ShowTruckState();

	cout << endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = (Truck*)pcar2;		// 딱봐도 문제인 형변환
	ptruck2->ShowTruckState();

	return 0;
}
