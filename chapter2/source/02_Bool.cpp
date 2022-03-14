#include <iostream>
using namespace std;

// 1. true�� false
// c++ ������ ���̻� ������ ��������� �������� �ʾƵ� bool�ڷ��� �� true/false�� ����Ҽ� �ִ�.

// 2) 
bool IsPositive(int num)
{
	if (num <= 0)
		return false;
	else
		return true;
}

int main(void)
{
	std::cout << "------------ < 1) true/false ����  > ----------------" << std::endl;
	// 1) true/false ����
	// c++ ������ ���̻� ������ ��������� �������� �ʾƵ� bool�ڷ��� �� true/false�� ����Ҽ� �ִ�.
	int num_1 = 10;
	int i = 0;

	cout << "true: " << true << endl;					// �ܼ� ��½� true	= 1
	cout << "false: " << false << endl;					//            false = 0

	while (true)				// while�� ���ǽ��� true�� ���� �ݺ�
	{
		cout << i++ << ' ';
		if (i > num_1)			// ���ѹݺ�while Ż��
			break;				
	}
	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;				// 1 = int			=> 4 byte
	cout << "sizeof 0: " << sizeof(1) << endl;				// 0 = int			=> 4 byte
	cout << "sizeof true: " << sizeof(true) << endl;		// true = bool		=> 1 byte
	cout << "sizeof false: " << sizeof(false) << endl;		// false = bool		=> 1 byte

	// * ��°�� *
	// true: 1
	// false : 0
	// 0 1 2 3 4 5 6 7 8 9 10
	// sizeof 1 : 4
	// sizeof 0 : 4
	// sizeof true : 1
	// sizeof false : 1


	std::cout << "------------ < 2) bool �ڷ����� ����  > ----------------" << std::endl;
	// 2) bool �ڷ����� ����
	bool isPos;					// bool�� �⺻�ڷ����̹Ƿ� ���� ����� ����� �����ϴ�.(�Լ��� ���� �Ű����� �Ǵ� ����ڷ������ε� ��밡��)
	int num_2;
	cout << "Input number : ";
	cin >> num_2;

	isPos = IsPositive(num_2);

	if (isPos)
		cout << "Positive number" << endl;
	else
		cout << "Negative number" << endl;

	// * ��°�� *
	// Input number : 12
	// Positive number

	
	return 0;

}