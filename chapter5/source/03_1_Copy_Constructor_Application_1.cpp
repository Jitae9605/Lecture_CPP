#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 3_1. 복사생성자 심화
// 반환을 통한 복사생성자 호출 (임시객체의 생성)

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

	Sosimple(const Sosimple& copy) :num(copy.num)		// 복사생성자의 디폴트 - 따로 언급안해도 원래있음(숨겨져서 안보일뿐)
	{
		cout << "Called Sosimple(Sosimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
	}
};

void simplefuncobj(Sosimple ob)
{
	ob.ShowSimpleData();
}

int main(void)
{
	Sosimple obj(7);
	cout << "함수 호출전" << endl;
	simplefuncobj(obj);
	cout << "함수 호출후" << endl;
	
	// * 출력결과 *
	// 함수 호출전
	// Called Sosimple(Sosimple & copy)
	// 7
	// 함수 호출후

	return 0;
}