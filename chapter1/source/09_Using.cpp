#include<iostream>

// 9. using

// 1)
namespace Hybrid
{
	void HybFunc(void)
	{
		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespacer Hybrid!" << std::endl;
	}
}

// 2)
using std::cin;
using std::endl;
using std::cout;

// 3)
using namespace std;		// std �̸��������� ��� �Լ��� ����Ҷ� std::�� ����

int main(void)
{

	std::cout << "------------ < 1) using�� �̿��� �̸������� ���  > ----------------" << std::endl;
	// 1) using�� �̿��� �̸������� ���

	using Hybrid::HybFunc;				// == HybFunc�Լ��� �տ� �ڵ����� Hybrid �̸������� ��õȴ�.(��, �������� - �ܺγ� Ÿ �Լ� �������� ��뿡�� �̸����� ����ؾ���)
	HybFunc();							//															(��, using�� �������� �����ϸ� �������)

	// * ��°�� *
	// So simple function!
	// In namespacer Hybrid!

	std::cout << "------------ < 2) using�� �̿��� ���� �Լ����  > ----------------" << std::endl;
	// 2) using�� �̿��� ���� �Լ����
	// �������� using�� ���� cin,endl,cout�� ����Ҷ� �տ� std::�� �����ʾƵ� �ǰ� �� -> ����

	int num = 20;
	cout << "Hello World!" << endl;
	cout << "Hello " << "World!" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;

	// * ��°�� *
	// Hello World!
	// Hello World!
	// 20 A 3.14

	std::cout << "------------ < 3) using�� �̿��� ���� �̸��������  > ----------------" << std::endl;
	// 3) using�� �̿��� ���� �̸��������
	// using namespace std�� �̿��ϸ� �Լ��ϳ��ϳ��� �ƴ϶� std������ ������ std::��� �̸����� ��þ��� ����� ������
	
	int num = 20;
	cout << "Hello World!" << endl;
	cout << "Hello " << "World!" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;

	// * ��°�� *
	// Hello World!
	// Hello World!
	// 20 A 3.14

	return 0;
}