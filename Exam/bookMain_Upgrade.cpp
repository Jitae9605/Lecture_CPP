#include<iostream>
#include<cstring>
#include<vector>
#include<Windows.h>
#pragma warning(disable:4996)

using namespace std;

class Product			// 상품 클래스
{
private:
	int idx;			// 상품번호
	int price;			// 가격
	char* description;	// 설명
public:
	Product(int aidx, int aprice, char* adescription) :idx(aidx), price(aprice)	// 상품추가(공통)
	{
		description = new char[strlen(adescription) + 1];
		strcpy(description, adescription);
	}

	virtual void getProduct()	// 상품 상세정보출력(공통)
	{
		cout << " idx : " << idx + 1 << endl;
		cout << " price : " << price << endl;
		cout << " description : " << this->description << endl;

	}

	virtual void DeleteProduct()	// 상품 삭제(공통)
	{
		delete[]description;
	}
};

class Book :public Product		// 책 클래스 : 상품클래스 상속
{
private:
	char* title;				// 책이름
	char* write;				// 저자
	char* publisher;			// 출판사
public:
	Book(int aidx, int aprice, char* adescription, char* atitle, char* awrite, char* apublisher) // 상품추가(공통 + book)
		:Product(aidx, aprice, adescription)
	{
		title = new char[strlen(atitle) + 1];
		strcpy(title, atitle);

		write = new char[strlen(awrite) + 1];
		strcpy(write, awrite);

		publisher = new char[strlen(apublisher) + 1];
		strcpy(publisher, apublisher);
	}

	void getProduct()		// 상품 상세정보출력(공통 + book)
	{

		Product::getProduct();
		cout << " title : " << this->title << endl;
		cout << " write : " << this->write << endl;
		cout << " publisher : " << this->publisher << endl << endl;

	}

	void DeleteProduct()			// 상품 삭제(공통 + book)
	{
		Product::DeleteProduct();
		delete[]title;
		delete[]write;
		delete[]publisher;
	}

};

class CD :public Product			// CD 클래스 : 상품클래스 상속
{
private:
	char* title;					// 이름
	char* singer;					// 가수이름
public:
	CD(int aidx, int aprice, char* adescription, char* atitle, char* asinger) // 상품추가(공통 + CD)
		:Product(aidx, aprice, adescription)
	{
		title = new char[strlen(atitle) + 1];
		strcpy(title, atitle);

		singer = new char[strlen(asinger) + 1];
		strcpy(singer, asinger);
	}
	void getProduct()		// 상품 상세정보출력(공통 + CD)
	{
		Product::getProduct();
		cout << " title : " << this->title << endl;
		cout << " singer : " << this->singer << endl << endl;
	}

	void DeleteProduct()			// 상품 삭제(공통 + CD)
	{
		Product::DeleteProduct();
		delete[]title;
		delete[]singer;
	}

};

class CellPhone :public Product			// 휴대폰 클래스 : 상품클래스 상속
{
private:
	char* model;						// 모델명
	char* manufacturer;						// 브랜드명
public:
	CellPhone(int aidx, int aprice, char* adescription, char* amodel, char* amanufacturer)	// 상품추가(공통 + CellPhone)
		:Product(aidx, aprice, adescription)
	{
		model = new char[strlen(amodel) + 1];
		strcpy(model, amodel);

		manufacturer = new char[strlen(amanufacturer) + 1];
		strcpy(manufacturer, amanufacturer);
	}
	void getProduct()					// 상품 상세정보출력(공통 + 휴대폰)	
	{

		Product::getProduct();
		cout << " model : " << this->model << endl;
		cout << " manufacturer : " << this->manufacturer << endl << endl;
	}

	void DeleteProduct()			// 상품 삭제(공통 + 휴대폰)
	{
		Product::DeleteProduct();
		delete[]model;
		delete[]manufacturer;
	}
};

int main(void)
{
	vector<int> book_list;			// book 상품번호 저장
	vector<int> cd_list;			// cd 상품번호 저장
	vector<int> cellphone_list;		// CellPhone 상품번호 저장

	static int idx = 0;
	Product* pobj[100];				// 상품목록(100개)
	while (1)
	{
		int Select_main;		// 메인메뉴
		cout << " +++++++++++++++ POS ++++++++++++++++" << endl << endl;
		cout << " 1. 상품추가" << endl;
		cout << " 2. 상품조회" << endl;
		cout << " 3. 상품삭제" << endl;
		cout << " 4. 종    료" << endl << endl;
		cout << " 선택 : ";
		cin >> Select_main;

		if (Select_main == 1)					// 1. 상품추가
		{
			while (1)
			{
				system("cls");
				int Select_Add;
				cout << " +++++++++++++++ 상품추가 ++++++++++++++++" << endl << endl;
				cout << " 1. BOOK" << endl;
				cout << " 2. CD" << endl;
				cout << " 3. CELL PHONE" << endl;
				cout << " 4. 뒤로가기" << endl << endl;
				cout << " 선택 : ";
				cin >> Select_Add;

				if (Select_Add == 1)			// 1.1 book 추가
				{
					system("cls");
					cout << "idx : " << idx + 1 << endl;

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

				else if (Select_Add == 2)		// 1.2 cd 추가
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

				else if (Select_Add == 3)		// 1.3 CellPhone 추가
				{
					system("cls");
					cout << "idx : " << idx + 1 << endl;

					int aprice;
					cout << "price : "; cin >> aprice;

					char adescription[20];
					cout << "description : "; cin >> adescription;

					char amodel[20];
					cout << "model : "; cin >> amodel;

					char amanufacturer[20];
					cout << "manufacturer : "; cin >> amanufacturer;

					pobj[idx] = new CellPhone(idx, aprice, adescription, amodel, amanufacturer);
					cellphone_list.push_back(idx);
					idx++;
				}

				else if (Select_Add == 4)		// 1.4 뒤로가기
				{
					system("cls");
					break;
				}

				else
				{
					system("cls");
					while (getchar() != '\n');
					cout << " 잘못된 입력값입니다." << endl;
				}
			}


		}

		else if (Select_main == 2)				// 2. 상품조회
		{
			while (1)
			{
				system("cls");
				int Select_view = 0;
				cout << " +++++++++++++++ 상품조회 ++++++++++++++++" << endl << endl;
				cout << " 1. BOOK" << endl;
				cout << " 2. CD" << endl;
				cout << " 3. CELL PHONE" << endl;
				cout << " 4. 뒤로가기" << endl << endl;
				cout << " 선택 : ";
				cin >> Select_view;


				if (Select_view == 1)				// 2.1 book 목록출력
				{
					system("cls");
					vector<int>::iterator iter_book;
					cout << " ----- < Book 등록된 상품목록 > ----- " << endl << endl;
					for (iter_book = book_list.begin(); iter_book != book_list.end(); iter_book++)
					{
						pobj[*iter_book]->getProduct();
						cout << " ----------------------------------" << endl << endl;
					}
					system("pause");
					system("cls");
				}

				else if (Select_view == 2)			// 2.2 cd 목록출력
				{
					system("cls");
					vector<int>::iterator iter_cd;
					cout << " ----- < CD 등록된 상품목록 > ----- " << endl << endl;
					for (iter_cd = cd_list.begin(); iter_cd != cd_list.end(); iter_cd++)
					{
						pobj[*iter_cd]->getProduct();
						cout << " ----------------------------------" << endl << endl;
					}
					system("pause");
					system("cls");
				}

				else if (Select_view == 3)			// 2.3 CellPhone 목록출력
				{
					system("cls");
					vector<int>::iterator iter_cellphone;
					cout << " ----- < CellPhone 등록된 상품목록 > ----- " << endl << endl << endl;
					for (iter_cellphone = cellphone_list.begin(); iter_cellphone != cellphone_list.end(); iter_cellphone++)
					{
						pobj[*iter_cellphone]->getProduct();
						cout << " ----------------------------------" << endl << endl;
					}
					system("pause");
					system("cls");
				}

				else if (Select_view == 4)		// 2.4 뒤로가기
				{
					system("cls");
					break;
				}

				else
				{
					system("cls");
					while (getchar() != '\n');
					cout << " 잘못된 입력값입니다." << endl;
				}
			}

		}

		else if (Select_main == 3)				// 3.상품삭제
		{
			while (1)
			{
				system("cls");
				int Select_delete = 0;
				cout << " +++++++++++++++ 상품삭제 ++++++++++++++++" << endl << endl;
				cout << " 1. BOOK" << endl;
				cout << " 2. CD" << endl;
				cout << " 3. CELL PHONE" << endl;
				cout << " 4. 뒤로가기" << endl << endl;
				cout << " 선택 : ";
				cin >> Select_delete;

				if (Select_delete == 1)					// 3.1 book 삭제
				{
					system("cls");
					int Check_find = 0;
					int Delete_Product = 0;
					vector<int>::iterator iter_book;

					for (iter_book = book_list.begin(); iter_book != book_list.end(); iter_book++)
					{
						pobj[*iter_book]->getProduct();
					}

					cout << " 삭제하고자 하는 상품 번호를 입력하세요 :";
					cin >> Delete_Product;
					Delete_Product--;
					cout << endl;

					for (iter_book = book_list.begin(); iter_book != book_list.end(); iter_book++)
					{
						if (*iter_book == Delete_Product)
						{
							Check_find = 1;
							pobj[Delete_Product]->DeleteProduct();
							delete pobj[Delete_Product];
							book_list.erase(iter_book);
							cout << Delete_Product+1 << " 번 상품 삭제되었습니다." << endl;
							system("pause");
							break;
						}
					}
					if (Check_find == 0)
					{
						cout << " 해당상품을 찾을수 없습니다." << endl;
						system("pause");
					}

				}

				else if (Select_delete == 2)			// 3.2 cd 삭제
				{
					system("cls");
					int Check_find = 0;
					int Delete_Product = 0;
					vector<int>::iterator iter_cd;

					for (iter_cd = cd_list.begin(); iter_cd != cd_list.end(); iter_cd++)
					{
						pobj[*iter_cd]->getProduct();
					}

					cout << " 삭제하고자 하는 상품 번호를 입력하세요 :";
					cin >> Delete_Product;
					Delete_Product--;
					cout << endl;


					for (iter_cd = cd_list.begin(); iter_cd != cd_list.end(); iter_cd++)
					{
						if (*iter_cd == Delete_Product)
						{
							Check_find = 1;
							pobj[Delete_Product]->DeleteProduct();
							delete pobj[Delete_Product];
							cd_list.erase(iter_cd);
							cout << Delete_Product+1 << " 번 상품 삭제되었습니다." << endl;
							system("pause");
							break;
						}
					}

					if (Check_find == 0)
					{
						cout << " 해당상품을 찾을수 없습니다." << endl;
						system("pause");
					}
				}

				else if (Select_delete == 3)			// 3.3 cellPhone 삭제
				{
					system("cls");
					int Check_find = 0;
					int Delete_Product = 0;
					vector<int>::iterator iter_cellphone;

					for (iter_cellphone = cellphone_list.begin(); iter_cellphone != cellphone_list.end(); iter_cellphone++)
					{
						pobj[*iter_cellphone]->getProduct();
					}

					cout << " 삭제하고자 하는 상품 번호를 입력하세요 :";
					cin >> Delete_Product;
					Delete_Product--;
					cout << endl;


					for (iter_cellphone = cellphone_list.begin(); iter_cellphone != cellphone_list.end(); iter_cellphone++)
					{
						if (*iter_cellphone == Delete_Product)
						{
							Check_find = 1;
							pobj[Delete_Product]->DeleteProduct();
							delete pobj[Delete_Product];
							cellphone_list.erase(iter_cellphone);
							cout << Delete_Product+1 << " 번 상품 삭제되었습니다." << endl;
							system("pause");
							break;
						}
					}
					if (Check_find == 0)
					{
						cout << " 해당상품을 찾을수 없습니다." << endl;
						system("pause");
					}
				}

				else if (Select_delete == 4)			// 3.4 뒤로가기
				{
					system("cls");
					break;
				}

				else
				{
					while (getchar() != '\n');
					cout << " 잘못된 입력값입니다." << endl;
				}
			}
		}

		else if (Select_main == 4)						// 4.프로그램종료
		{
			exit(1);
		}

		else
		{
			system("cls");
			while (getchar() != '\n');
			cout << " 잘못된 입력값입니다." << endl;
		}
	}

	return 0;
}