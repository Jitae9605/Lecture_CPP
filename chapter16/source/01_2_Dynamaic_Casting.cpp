#include<iostream>
using namespace std;

// 1_2.다이나믹 캐스팅
// dynamic_casting =  상속관계에서 안전한 형변환
//  -> 상속관계에 있는 유도클래스의 포인터 및 참조형 데이터를 기초클래스의 포인터 및 참조형 데이터로 형변환 한다는 의미


class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) :fuelGauge(fuel)
	{ }
	void ShowCarState() { cout << "잔여 연료량 : " << fuelGauge << endl; }
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
		cout << "화물의 무게 : " << freighWeight << endl;
	}
};

int main(void)
{
	// Car* pcar1 = new Truck(80, 200);
	// Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);		// 컴파일 에러!

	// Car* pcar2 = new Car(120);
	// Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);		// 컴파일 에러!

	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Truck*>(ptruck3);				// 컴파일 OK!


	return 0;
}
