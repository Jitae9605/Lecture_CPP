#include<iostream>
using namespace std;

// 4_2.클래스템플릿과 Static멤버변수
// static은 클래스내에서 공유되는 변수이므로 템플릿클래스별로 변수가 유지된다.

template <typename T>
class SimpleStaticMem
{
private:
	static T mem;
public:
	void AddMem(T num) { mem += num; }
	void ShowMem() { cout << mem << endl; }
};

template <typename T>
T SimpleStaticMem<T>::mem = 0;		// 스태택멤버 초기화

int main(void)
{
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;
	obj1.AddMem(2);					// SimpleStaticMem<int> 클래스 내부의 static멤버 mem = 0 + 2 = 2
	obj2.AddMem(3);					// SimpleStaticMem<int> 클래스 내부의 static멤버 mem = 2 + 3 = 5
	obj1.ShowMem();
	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);				// SimpleStaticMem<long> 클래스 내부의 static멤버 mem = 0 + 100 = 100
	obj4.ShowMem();

	// * 출력 결과 *
	// 5
	// 100

	return 0;

}