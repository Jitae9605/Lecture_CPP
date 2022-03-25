#include<iostream>
#include<cstring>
#include<vector>
#include<Windows.h>
#pragma warning(disable:4996)
using namespace std;

class Product
{
private:
	int idx;
	int price;
	char* description;
public:
	Product(int aidx, int aprice, char* adescription) :idx(aidx), price(aprice)
	{
		description = new char[strlen(adescription) + 1];
		strcpy(description, adescription);
	}

	virtual void getProduct()
	{ 
		cout << "idx : " << idx+1 << endl;
		cout << "price : " << price << endl;
		cout << "description : " << this->description << endl;

	}


};

class Book:public Product
{
private:
	char* title;
	char* write;
	char* publisher;
public:
	Book(int aidx, int aprice, char* adescription, char* atitle, char* awrite, char* apublisher)
		:Product(aidx,aprice, adescription)
	{
		title = new char[strlen(atitle) + 1];
		strcpy(title, atitle);

		write = new char[strlen(awrite) + 1];
		strcpy(write, awrite);

		publisher = new char[strlen(apublisher) + 1];
		strcpy(publisher, apublisher);
	}
	void getProduct()
	{
		cout << "Book 등록된 상품목록" << endl << endl;
		Product::getProduct();
		cout << "title : " << this->title << endl;
		cout << "write : " << this->write << endl;
		cout << "publisher : " << this->publisher << endl << endl;

	}
};

class CD :public Product
{
private:
	char* title;
	char* singer;
public:
	CD(int aidx, int aprice, char* adescription, char* atitle, char* asinger)
		:Product(aidx, aprice, adescription)
	{
		title = new char[strlen(atitle) + 1];
		strcpy(title, atitle);

		singer = new char[strlen(asinger) + 1];
		strcpy(singer, asinger);
	}
	void getProduct()
	{
		cout << "CD 등록된 상품목록" << endl << endl;
		Product::getProduct();
		cout << "title : " << this->title << endl;
		cout << "singer : " << this->singer << endl<<endl;
	}

};

class CellPhone :public Product
{
private:
	char* model;
	char* brand;
public:
	CellPhone(int aidx, int aprice, char* adescription, char* amodel, char* abrand)
		:Product(aidx, aprice, adescription)
	{
		model = new char[strlen(amodel) + 1];
		strcpy(model, amodel);

		brand = new char[strlen(abrand) + 1];
		strcpy(brand, abrand);
	}
	void getProduct()
	{
		cout << "CellPhone 등록된 상품목록" << endl << endl;
		Product::getProduct();
		cout << "model : " << this->model << endl;
		cout << "brand : " << this->brand << endl << endl;
	}

};

int main(void)
{
	vector<int> book_list;
	vector<int> cd_list;
	vector<int> cellphone_list;

	static int idx = 0;
	Product* pobj[100];
	while (1)
	{
		int Select_main;
		cout << " +++++++++++++++ POS ++++++++++++++++" << endl << endl;
		cout << "1. 상품추가" << endl;
		cout << "2. 상품조회" << endl;
		cout << "3. 종    료" << endl;
		cout << "선택 : ";
		cin >> Select_main;

		if (Select_main == 1)
		{
			while (1)
			{
				system("cls");
				int Select_Add;
				cout << " +++++++++++++++ 상품추가 ++++++++++++++++" << endl << endl;
				cout << "1. BOOK" << endl;
				cout << "2. CD" << endl;
				cout << "3. CELL PHONE" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "선택 : ";
				cin >> Select_Add;

				if (Select_Add == 1)
				{
					system("cls");
					cout << "idx : " << idx+1 << endl;

					int aprice;
					cout << "price : "; cin >> aprice;

					char adescription[20];
					cout << "description : "; cin >> adescription;

					char atitle[20];
					cout << "title : "; cin >> atitle;

					char awrite[20];
					cout << "write : "; cin >> awrite;

					char apublisher[20];
					cout << "publisher : "; cin >> apublisher;

					pobj[idx] = new Book(idx, aprice, adescription, atitle, awrite, apublisher);
					book_list.push_back(idx);
					idx++;

				}

				else if (Select_Add == 2)
				{
					system("cls");
					cout << "idx : " << idx + 1 << endl;

					int aprice;
					cout << "price : "; cin >> aprice;

					char adescription[20];
					cout << "description : "; cin >> adescription;

					char atitle[20];
					cout << "title : "; cin >> atitle;

					char asinger[20];
					cout << "singer : "; cin >> asinger;

					pobj[idx] = new CD(idx, aprice, adescription, atitle, asinger);
					cd_list.push_back(idx);
					idx++;
				}

				else if (Select_Add == 3)
				{
					system("cls");
					cout << "idx : " << idx + 1 << endl;

					int aprice;
					cout << "price : "; cin >> aprice;

					char adescription[20];
					cout << "description : "; cin >> adescription;

					char amodel[20];
					cout << "model : "; cin >> amodel;

					char abrand[20];
					cout << "brand : "; cin >> abrand;

					pobj[idx] = new CellPhone(idx, aprice, adescription, amodel, abrand);
					cellphone_list.push_back(idx);
					idx++;
				}

				else if (Select_Add == 4)
				{
					system("cls");
					break;
				}

				else
				{
					while (getchar() != '\n');
					cout << "잘못된 입력값입니다." << endl;
				}
			}

				
		}
	
		else if (Select_main == 2)
		{
			system("cls");
			int Select_view = 0;
			cout << " +++++++++++++++ 상품조회 ++++++++++++++++" << endl << endl;
			cout << "1. BOOK" << endl;
			cout << "2. CD" << endl;
			cout << "3. CELL PHONE" << endl;
			cout << "선택 : ";
			cin >> Select_view;


			if (Select_view == 1)
			{
				vector<int>::iterator iter_book;

				for (iter_book = book_list.begin(); iter_book != book_list.end(); iter_book++)
				{
					pobj[*iter_book]->getProduct();
				}
				system("pause");
				system("cls");
			}

			else if (Select_view == 2)
			{
				vector<int>::iterator iter_cd;

				for (iter_cd = cd_list.begin(); iter_cd != cd_list.end(); iter_cd++)
				{
					pobj[*iter_cd]->getProduct();
				}
				system("pause");
				system("cls");
			}

			else if (Select_view == 3)
			{
				vector<int>::iterator iter_cellphone;

				for (iter_cellphone = cellphone_list.begin(); iter_cellphone != cellphone_list.end(); iter_cellphone++)
				{
					pobj[*iter_cellphone]->getProduct();
				}
				system("pause");
				system("cls");
			}

			else
			{
				while (getchar() != '\n');
				cout << "잘못된 입력값입니다." << endl;
			}
				
		}
		
		else if (Select_main == 3)
		{
			exit(1);
		}

		else
		{
			while (getchar() != '\n');
			cout << "잘못된 입력값입니다." << endl;
		}
			
			
	}

	return 0;
}