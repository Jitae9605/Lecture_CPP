#include<iostream>
using namespace std;

// 2_3. Ŭ���� ���ø��� �κ�Ư��ȭ

template <typename T1, typename T2>
class MySimple
{
public:
	void WhoAreYou()
	{
		cout << "size of T1 : " << sizeof(T1) << endl;
		cout << "size of T2 : " << sizeof(T2) << endl;
		cout << "<typename T1, typename T2>" << endl;
	}
};

template <>
class MySimple<int, double>
{
public:
	void WhoAreYou()
	{
		cout << "size of int : " << sizeof(int) << endl;
		cout << "size of double : " << sizeof(double) << endl;
		cout << "<int, double>" << endl;
	}
};

//template <typename T1>
//class MySimple<T1, double>
//{
//public:
//	void WhoAreYou()
//	{
//		cout << "size of T1 : " << sizeof(T1) << endl;
//		cout << "size of double : " << sizeof(double) << endl;
//		cout << "<T1, double>" << endl;
//	}
//};

int main(void)
{
	MySimple<char, double> obj1;
	obj1.WhoAreYou();

	MySimple<int, long> obj2;
	obj2.WhoAreYou();

	MySimple<int, double> obj3;
	obj3.WhoAreYou();

	// * ��°�� *
	// size of T1 : 1
	// size of T2 : 8
	// < typename T1, typename T2 >
	// size of T1 : 4
	// size of T2 : 4
	// < typename T1, typename T2 >
	// size of int : 4
	// size of double : 8
	// < int, double >

	
	// * �ּ������� ��°�� * 
	// size of T1 : 1
	// size of double : 8
	// < T1, double >
	// size of T1 : 4
	// size of T2 : 4
	// < typename T1, typename T2 >
	// size of int : 4
	// size of double : 8
	// < int, double >

	return 0;
}