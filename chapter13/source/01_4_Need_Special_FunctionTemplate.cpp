#include<iostream>
using namespace std;

// 1_4 �Լ����ø��� Ư��ȭ�� �ʿ伺

template <typename T>		// �Լ����ø�
T Max(T a, T b)		// ���⼭ T�� ������ �ڷ����̴� ���߿� �츮�� ����
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;		// ��� �ǹ̰� ���� - �ּҰ��� ũ�⸦ ���ϰԵȴ�.

	// * ��°�� *
	// 15
	// T
	// 7.5
	// Simple

	return 0;

}

