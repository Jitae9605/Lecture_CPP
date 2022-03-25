#include<iostream>
using namespace std;

// 4_2.Ŭ�������ø��� Static�������
// static�� Ŭ���������� �����Ǵ� �����̹Ƿ� ���ø�Ŭ�������� ������ �����ȴ�.

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
T SimpleStaticMem<T>::mem = 0;		// �����ø�� �ʱ�ȭ

int main(void)
{
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;
	obj1.AddMem(2);					// SimpleStaticMem<int> Ŭ���� ������ static��� mem = 0 + 2 = 2
	obj2.AddMem(3);					// SimpleStaticMem<int> Ŭ���� ������ static��� mem = 2 + 3 = 5
	obj1.ShowMem();
	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);				// SimpleStaticMem<long> Ŭ���� ������ static��� mem = 0 + 100 = 100
	obj4.ShowMem();

	// * ��� ��� *
	// 5
	// 100

	return 0;

}