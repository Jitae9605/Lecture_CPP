#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// 4_3.Catch를 통해 예외상황이 적절한가를 찾기까지의 expn의 흐름과정

class AAA
{
public:
	void ShowYou() { cout << "AAA excption!" << endl; }
};

class BBB :public AAA
{
public:
	void ShowYou() { cout << "BBB excption!" << endl; }
};

class CCC :public BBB
{
public:
	void ShowYou() { cout << "CCC excption!" << endl; }
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
		throw BBB();
	else
		throw CCC();

}

int main(void)
{
	try
	{
		ExceptionGenerator(3);
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	/*catch(AAA& expn)
	{
		cout << "Catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB& expn)
	{
		cout << "Catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (CCC& expn)
	{
		cout << "Catch(CCC& expn)" << endl;
		expn.ShowYou();
	}*/
	catch (CCC& expn)
	{
		cout << "Catch(CCC& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB& expn)
	{
		cout << "Catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (AAA& expn)
	{
		cout << "Catch(AAA& expn)" << endl;
		expn.ShowYou();
	}

	// * 출력결과 1 * - 주석처리부분을 풀고 아래부분을 추석처리했을경우
	// Catch(AAA& expn)
	// AAA excption!

	// AAA클래스 상속했으므로 바로 걸림

	// * 출력결과 2 *
	// Catch(CCC& expn)
	// CCC excption!


	return 0;
}