#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 3_2. ��������� ��ȭ
// 

using namespace std;

class Sosimple
{
private:
	int num;

public:
	Sosimple(int n) :num(n)
	{
		// empty
	}

	Sosimple(const Sosimple& copy) :num(copy.num)		// ����������� ����Ʈ - ���� ��޾��ص� ��������(�������� �Ⱥ��ϻ�)
	{
		cout << "Called Sosimple(Sosimple &copy)" << endl;
	}

	Sosimple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void ShowSimpleData()
	{
		cout <<"num : "<< num << endl;

	}
};

Sosimple simplefuncobj(Sosimple ob)
{
	cout << "return ����" << endl;
	return ob;							// �ӽð�ü
}

int main(void)
{
	Sosimple obj(7);
	simplefuncobj(obj).AddNum(30).ShowSimpleData();
	obj.ShowSimpleData();


	// * ��°�� *
	// Called Sosimple(Sosimple &copy)
	// return ����
	// Called Sosimple(Sosimple & copy)
	// num : 37
	// num : 7

	return 0;
}