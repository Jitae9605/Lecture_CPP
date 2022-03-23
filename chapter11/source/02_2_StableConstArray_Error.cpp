#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 2_2 const�Լ��� �̿��� �����ε� (�����߻�)

class bouondChaeckIntArray
{
private:
	int* arr;
	int arrlen;
	bouondChaeckIntArray(const bouondChaeckIntArray& arr) { }
	bouondChaeckIntArray& operator=(const bouondChaeckIntArray& arr) { }

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

	int GetArrLen() const { return arrlen; }

	~bouondChaeckIntArray()
	{
		delete[]arr;
	}
};

void ShowAllData(const bouondChaeckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
	{
		cout << ref[idx] << endl;
	}
}

int main(void)
{
	bouondChaeckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	ShowAllData(arr);

	// * ��°�� *
	// ������ ���� �߻�

	return 0;
}