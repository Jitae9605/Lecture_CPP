#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 4. 복사생성자에 의한 임시객체생성
// 

using namespace std;


class Temporary
{
private:
	int num;
public:
	Temporary(int n) :num(n)
	{
		cout << "create obj :" << num << endl;
	}

	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}

	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);		// 이 문장 끝나자마자 이름없는 임시객체는 즉시 소멸자 발동
	cout << "********************** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();		// 이 문장 끝나자마자 이름없는 임시객체는 즉시 소멸자 발동
	cout << "*********************** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);		// 이름없는 객체를 이름없는 객체가 참조하는 것		 			
	cout << "*********************** end of main!" << endl << endl;

	// * 출력결과 *
	// create obj :100
	// destroy obj : 100
	// * ********************* after make!
	// 
	// create obj : 200
	// My num is 200
	// destroy obj : 200
	// * ********************** after make!
	// 
	// create obj : 300
	// * ********************** end of main!
	// 
	// destroy obj : 300
	return 0;
}