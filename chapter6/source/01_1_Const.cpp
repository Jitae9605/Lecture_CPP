#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 1. Const 함수에 대한 이해
// 

using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n):num(n)
	{ }
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num : " << num << endl;
	}
};

int main(void)
{
	const SoSimple obj(7);
	// obj.AddNum(20);
	obj.ShowData();

	// * 출력결과 *
	// num : 7
	return 0;
}