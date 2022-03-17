#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 4. ��������ڿ� ���� �ӽð�ü����
// 

using namespace std;


class Temporary
{
private:
	int num;
public:
	Temporary(int n) :num(n)
	{
		cout << "create obj :" << num << endl;
	}

	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}

	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);		// �� ���� �����ڸ��� �̸����� �ӽð�ü�� ��� �Ҹ��� �ߵ�
	cout << "********************** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();		// �� ���� �����ڸ��� �̸����� �ӽð�ü�� ��� �Ҹ��� �ߵ�
	cout << "*********************** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);		// �̸����� ��ü�� �̸����� ��ü�� �����ϴ� ��		 			
	cout << "*********************** end of main!" << endl << endl;

	// * ��°�� *
	// create obj :100
	// destroy obj : 100
	// * ********************* after make!
	// 
	// create obj : 200
	// My num is 200
	// destroy obj : 200
	// * ********************** after make!
	// 
	// create obj : 300
	// * ********************** end of main!
	// 
	// destroy obj : 300
	return 0;
}