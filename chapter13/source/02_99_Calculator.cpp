#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;


template <typename T>
class Cal
{
private:
	T num1, num2, res;
public:
	Cal(T anum1, T anum2):num1(anum1),num2(anum2),res(0)
	{ }

	Cal(T aanum1 = 0, T aanum2 = 0,  T aanum3 = 0)
	{ 
		int anum1, anum2;
		cout << "두 수를 입력하시오 : ";
		cin >> anum1 >> anum2;
		num1 = anum1;
		num2 = anum2;
		res = 0;
	}

	T Sum()
	{
		res = num1 + num2;
		cout << "sum : " << res << endl;
		return res;
	}

	T Sub()
	{
		res = num1 - num2;
		cout << "sub : " << res << endl;
		return res;
	}

	T Mul()
	{
		res = num1 * num2;
		cout << "Mul : " << res << endl;
		return res;
	}

	T Div()
	{
		res = (double)num1 / (double)num2;
		cout << "Div : " << res << endl;
		return (double)res;
	}
		
};

int main(void)
{
	//Cal <int>c1(100, 10);
	Cal <double>c1(0,0,0);
	c1.Sum();
	c1.Sub();
	c1.Mul();
	c1.Div();

	return 0;
}