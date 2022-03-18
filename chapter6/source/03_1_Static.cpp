#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 3. static�� �̿�
// static�� Ư��
// ����� Ŭ������ ��� ��ü�� �����Ѵ�
// public���� ����Ǹ� Ŭ������ �̸��� ���� ȣ���� �����ϴ�.
// ��ü�� ����� �����ϴ� ���� �ƴϴ�

using namespace std;

void Counter()
{
	static int cnt;								// static���� ���������Ƿ� �Լ��� ������ cnt�� ������ ����ִ�
	cnt++;
	cout << "Current cnt : " << cnt << endl;
}



int main(void)
{
	for (int i = 0; i < 10; i++)
		Counter();					// cnt�� static�� �ƴϸ� cnt�� ȣ�⶧���� ������� ���� cnt�� ���� 
									//		=> Current cnt : 1 �� ��� ���

	// * ��°�� *
	// Current cnt : 1
	// Current cnt : 2
	// Current cnt : 3
	// Current cnt : 4
	// Current cnt : 5
	// Current cnt : 6
	// Current cnt : 7
	// Current cnt : 8
	// Current cnt : 9
	// Current cnt : 10

	return 0;
}