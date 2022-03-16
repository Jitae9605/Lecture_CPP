#include <iostream>
#pragma warning(disable:4996)

// Fruit_SalesSimulator_1���� ������ �߰�

using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money)	// ������
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult()
	{
		cout << "\t���� ��� : " << numOfApples << endl;
		cout << "\t�Ǹ� ���� : " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;			// private
	int numOfApples;		// private

public:
	FruitBuyer(int money)				// ������
	{
		numOfApples = 0;
		myMoney = money;
	}

	void BuyApples(FruitSeller& seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult()
	{
		cout << "\t���� �ܾ� : " << myMoney << endl;
		cout << "\t��� ���� : " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);	// �Ǹ���(seller) : ���� 1�� ���� = 1000��, ����� = 20��, �ʱ��ڱ� = 0��

	FruitBuyer buyer(5000);				// ������(buyer) :  �ʱ��ڱ� = 5000��

	buyer.BuyApples(seller, 2000);	// seller���Լ� 2000����ġ ���ϱ���
									//  => 2���� ����� ����	(�Ǹ��� ������� = -2, �ڱ� = + 2000) = (18	,	2000)
									//						(������ ������� = +2, �ڱ� = - 2000) = (2	,	3000)

	cout << "    < ���� [�Ǹ���]�� ��Ȳ >" << endl;
	seller.ShowSalesResult();
	cout << "    < ���� [������]�� ��Ȳ >" << endl;
	buyer.ShowBuyResult();

	// * ��°�� *
	//    < ����[�Ǹ���]�� ��Ȳ >
	//		 ���� ��� : 18
	//		 �Ǹ� ���� : 2000
	// 
	//    < ����[������]�� ��Ȳ >
	//		 ���� �ܾ� : 3000
	//		 ��� ���� : 2





	return 0;
}