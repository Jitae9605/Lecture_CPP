#include<iostream>
#include<cstring>
#include<vector>
#include<Windows.h>
#pragma warning(disable:4996)

using namespace std;

class Product			// ��ǰ Ŭ����
{
private:
	int idx;			// ��ǰ��ȣ
	int price;			// ����
	char* description;	// ����
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

class Book:public Product		// å Ŭ���� : ��ǰŬ���� ���
{
private:
	char* title;				// å�̸�
	char* write;				// ����
	char* publisher;			// ���ǻ�
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
		cout << " ----- < Book ��ϵ� ��ǰ��� > ----- " << endl << endl;
		Product::getProduct();
		cout << "title : " << this->title << endl;
		cout << "write : " << this->write << endl;
		cout << "publisher : " << this->publisher << endl << endl;

	}
};

class CD :public Product			// CD Ŭ���� : ��ǰŬ���� ���
{
private:
	char* title;					// �̸�
	char* singer;					// �����̸�
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
		cout << " ----- < CD ��ϵ� ��ǰ��� > ----- " << endl << endl;
		Product::getProduct();
		cout << "title : " << this->title << endl;
		cout << "singer : " << this->singer << endl<<endl;
	}

};

class CellPhone :public Product			// �޴��� Ŭ���� : ��ǰŬ���� ���
{
private:
	char* model;						// �𵨸�
	char* brand;						// �귣���
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
		cout << " ----- < CellPhone ��ϵ� ��ǰ��� > ----- " << endl << endl;
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
		int Select_main;		// ���θ޴�
		cout << " +++++++++++++++ POS ++++++++++++++++" << endl << endl;
		cout << "1. ��ǰ�߰�" << endl;
		cout << "2. ��ǰ��ȸ" << endl;
		cout << "3. ��    ��" << endl;
		cout << "���� : ";
		cin >> Select_main;

		if (Select_main == 1)					// 1. ��ǰ�߰�
		{
			while (1)
			{
				system("cls");
				int Select_Add;
				cout << " +++++++++++++++ ��ǰ�߰� ++++++++++++++++" << endl << endl;
				cout << "1. BOOK" << endl;
				cout << "2. CD" << endl;
				cout << "3. CELL PHONE" << endl;
				cout << "4. �ڷΰ���" << endl;
				cout << "���� : ";
				cin >> Select_Add;

				if (Select_Add == 1)			// 1.1 å�߰�
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

				else if (Select_Add == 2)		// 1.2 cd�߰�
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

				else if (Select_Add == 3)		// 1.3 �޴����߰�
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

				else if (Select_Add == 4)		// 1.4 �ڷΰ���
				{
					system("cls");
					break;
				}

				else
				{
					while (getchar() != '\n');
					cout << "�߸��� �Է°��Դϴ�." << endl;
				}
			}

				
		}
	
		else if (Select_main == 2)				// 2.��ǰ��ȸ
		{
			system("cls");
			int Select_view = 0;
			cout << " +++++++++++++++ ��ǰ��ȸ ++++++++++++++++" << endl << endl;
			cout << "1. BOOK" << endl;
			cout << "2. CD" << endl;
			cout << "3. CELL PHONE" << endl;
			cout << "���� : ";
			cin >> Select_view;


			if (Select_view == 1)				// 2.1 å ������
			{
				vector<int>::iterator iter_book;

				for (iter_book = book_list.begin(); iter_book != book_list.end(); iter_book++)
				{
					pobj[*iter_book]->getProduct();
				}
				system("pause");
				system("cls");
			}

			else if (Select_view == 2)			// 2.2 cd ������
			{
				vector<int>::iterator iter_cd;

				for (iter_cd = cd_list.begin(); iter_cd != cd_list.end(); iter_cd++)
				{
					pobj[*iter_cd]->getProduct();
				}
				system("pause");
				system("cls");
			}

			else if (Select_view == 3)			// 2.3 �޴��� ������
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
				cout << "�߸��� �Է°��Դϴ�." << endl;
			}
				
		}
		
		else if (Select_main == 3)				// 3.���α׷�����
		{
			exit(1);
		}

		else
		{
			while (getchar() != '\n');
			cout << "�߸��� �Է°��Դϴ�." << endl;
		}
			
			
	}

	return 0;
}