#include <iostream>
#pragma warning(disable:4996)

// Fruit_SalesSimulator_1에서 생성자 추가

using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money)	// 생성자
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
		cout << "\t남은 사과 : " << numOfApples << endl;
		cout << "\t판매 수익 : " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;			// private
	int numOfApples;		// private

public:
	FruitBuyer(int money)				// 생성자
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
		cout << "\t현재 잔액 : " << myMoney << endl;
		cout << "\t사과 갯수 : " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);	// 판매자(seller) : 과일 1개 가격 = 1000원, 현재고 = 20개, 초기자금 = 0원

	FruitBuyer buyer(5000);				// 구매자(buyer) :  초기자금 = 5000원

	buyer.BuyApples(seller, 2000);	// seller에게서 2000원어치 과일구매
									//  => 2개의 사과를 구매	(판매자 사과개수 = -2, 자금 = + 2000) = (18	,	2000)
									//						(구매자 사과개서 = +2, 자금 = - 2000) = (2	,	3000)

	cout << "    < 과일 [판매자]의 현황 >" << endl;
	seller.ShowSalesResult();
	cout << "    < 과일 [구매자]의 현황 >" << endl;
	buyer.ShowBuyResult();

	// * 출력결과 *
	//    < 과일[판매자]의 현황 >
	//		 남은 사과 : 18
	//		 판매 수익 : 2000
	// 
	//    < 과일[구매자]의 현황 >
	//		 현재 잔액 : 3000
	//		 사과 갯수 : 2





	return 0;
}