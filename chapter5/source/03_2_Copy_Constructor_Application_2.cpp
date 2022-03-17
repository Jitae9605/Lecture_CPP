#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 3_2. 복사생성자 심화
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

	Sosimple(const Sosimple& copy) :num(copy.num)		// 복사생성자의 디폴트 - 따로 언급안해도 원래있음(숨겨져서 안보일뿐)
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
	cout << "return 이전" << endl;
	return ob;							// 임시객체
}

int main(void)
{
	Sosimple obj(7);
	simplefuncobj(obj).AddNum(30).ShowSimpleData();
	obj.ShowSimpleData();


	// * 출력결과 *
	// Called Sosimple(Sosimple &copy)
	// return 이전
	// Called Sosimple(Sosimple & copy)
	// num : 37
	// num : 7

	return 0;
}