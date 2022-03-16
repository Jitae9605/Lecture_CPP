#include <iostream>
#pragma warning(disable:4996)

// 8. �����ڸ� private���� �����ϴ°͵� ����
// ������ �׷��� ������ ��ü���ο����� �����ؾ��Ѵ�.

using namespace std;

class AAA
{
private:
	int num;
public:
	AAA() : num(0) {}	// ����Ʈ ������
	AAA& CreateInitObj(int n) const						// 
	{
		AAA* ptr = new AAA(n);							// AAA(n)���� �����ϰ� �� ����� ����Ű�� AAA* ptr�� ���� �̸� ��ȯ
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }
private:
	AAA(int n) : num(n) {}								// 17���� AAA(n)���� AAA �� �����ǰ� �ϴ� ������ ������				
};

int main(void)
{
	AAA base;											// ����Ʈ�����ڿ� ���� ����
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);					// == [AAA& obj1] = [AAA* ptr] = [AAA(3)]
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);					// == [AAA& obj2] = [AAA* ptr] = [AAA(12)]
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;

	return 0;

	// * ��°�� *
	// 0
	// 3
	// 12
}