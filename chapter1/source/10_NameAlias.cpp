#include <iostream>
using namespace std;

// 10. �̸����� ��Ī����
// namespace�� ��ø�Ǿ������� �̵��� �̸��� �ѹ��� ���� �����ϰ� ������ֵ�

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1, num2;
		}
	}
}

int main(void)
{
	
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;		// AAA::BBC::CCC �� ABC�� ��Ī�� ����(typedef�� ���)
	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;

	// * ��°�� *
	// 20
	// 30

	return 0;
}