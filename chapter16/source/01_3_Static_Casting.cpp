#include<iostream>
using namespace std;

// 1_3.스태틱 캐스팅
// static_casting =  상속관계에서 무조건의 형변환
//  -> 유도/기초 클래스의 포인터 및 참조형 데이터를 아무조건없이 형변환시켜줌(위험! - 책임은 프로그래머의 몫)

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
	Car* pcar1 = new Truck(80, 200);					
	Truck* ptruck1 = static_cast<Truck*>(pcar1);		// 컴파일 OK!
	ptruck1->ShowTruckState();

	cout << endl;

	Car* pcar2 = new Car(120);							
	Truck* ptruck2 = static_cast<Truck*>(pcar2);		// 컴파일 OK! 하지만 weight값이 없으니 쓰레기값이 출력
	ptruck2->ShowTruckState();

	return 0;
}
