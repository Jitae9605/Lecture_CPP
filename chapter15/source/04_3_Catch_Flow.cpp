#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// 4_3.Catch�� ���� ���ܻ�Ȳ�� �����Ѱ��� ã������� expn�� �帧����

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

	// * ��°�� 1 * - �ּ�ó���κ��� Ǯ�� �Ʒ��κ��� �߼�ó���������
	// Catch(AAA& expn)
	// AAA excption!

	// AAAŬ���� ��������Ƿ� �ٷ� �ɸ�

	// * ��°�� 2 *
	// Catch(CCC& expn)
	// CCC excption!


	return 0;
}