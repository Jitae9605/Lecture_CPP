#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

//

class CTest
{
private:
	int money;
public:
	CTest(int m = 0) :money(m) {
		cout << "CTest »ý¼ºÀÚ" << endl;
	}
	int operator()() {
		return money;
	}
	void operator()(int m) {
		money += m;
	}

};

int main()
{
	CTest m;
	cout << m() << endl;
	m(100);
	cout << m() << endl;

	return 0;
}