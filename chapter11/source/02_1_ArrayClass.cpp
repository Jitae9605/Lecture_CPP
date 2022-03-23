#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 2. �迭Ŭ����

class bouondChaeckIntArray
{
private:
	int* arr;
	int arrlen;

public:
	bouondChaeckIntArray(int len) :arrlen(len)
	{
		arr = new int[len];
	}

	int& operator[] (int idx)							// []������ �����ε�
	{
		if (idx < 0 || idx >= arrlen)		// ����ó�� - �迭�̻��� ����ϸ� ��µǴ� �����Ⱚ ����� ��ü
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	~bouondChaeckIntArray()
	{
		delete[]arr;
	}
};

int main(void)
{
	bouondChaeckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;	
	for (int i = 0; i < 6; i++)		// 0 ~ 4���� ����� 5�� �����Ƿ� ����ó�� ����
	{
		cout << arr[i] << endl;
	}

	// * ��°�� *
	// 11
	// 22
	// 33
	// 44
	// 55
	// Array index out of bound exception

	return 0;
}