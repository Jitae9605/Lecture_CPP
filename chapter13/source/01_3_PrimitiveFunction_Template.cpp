#include<iostream>
using namespace std;

template<class T1, class T2>
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

int main(void)
{
	ShowData<char, int>(65);			// 65 = 'A'
	ShowData<char, int>(67);			// 67 = 'C'
	ShowData<char, double>(68.9);		// 68 = 'D'
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);

	// * 출력결과 *
	// A, 65
	// C, 67
	// D, 68.9
	// 69, 69.2
	// 70, 70.4
	return 0;
}