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
	Product(int aidx, int aprice, char* adescription) :idx(aidx), price(aprice)	// ��ǰ�߰�(����)
	{
		description = new char[strlen(adescription) + 1];
		strcpy(description, adescription);
	}

	virtual void getProduct()	// ��ǰ ���������(����)
	{
		cout << " idx : " << idx + 1 << endl;
		cout << " price : " << price << endl;
		cout << " description : " << this->description << endl;

	}

	virtual void DeleteProduct()	// ��ǰ ����(����)
	{
		delete[]description;
	}
};

class Book :public Product		// å Ŭ���� : ��ǰŬ���� ���
{
private:
	char* title;				// å�̸�
	char* write;				// ����
	char* publisher;			// ���ǻ�
public:
	Book(int aidx, int aprice, char* adescription, char* atitle, char* awrite, char* apublisher) // ��ǰ�߰�(���� + book)
		:Product(aidx, aprice, adescription)
	{
		title = new char[strlen(atitle) + 1];
		strcpy(title, atitle);

		write = new char[strlen(awrite) + 1];
		strcpy(write, awrite);

		publisher = new char[strlen(apublisher) + 1];
		strcpy(publisher, apublisher);
	}

	void getProduct()		// ��ǰ ���������(���� + book)
	{

		Product::getProduct();
		cout << " title : " << this->title << endl;
		cout << " write : " << this->write << endl;
		cout << " publisher : " << this->publisher << endl << endl;

	}

	void DeleteProduct()			// ��ǰ ����(���� + book)
	{
		Product::DeleteProduct();
		delete[]title;
		delete[]write;
		delete[]publisher;
	}

};

class CD :public Product			// CD Ŭ���� : ��ǰŬ���� ���
{
private:
	char* title;					// �̸�
	char* singer;					// �����̸�
public:
	CD(int aidx, int aprice, char* adescription, char* atitle, char* asinger) // ��ǰ�߰�(���� + CD)
		:Product(aidx, aprice, adescription)
	{
		title = new char[strlen(atitle) + 1];
		strcpy(title, atitle);

		singer = new char[strlen(asinger) + 1];
		strcpy(singer, asinger);
	}
	void getProduct()		// ��ǰ ���������(���� + CD)
	{
		Product::getProduct();
		cout << " title : " << this->title << endl;
		cout << " singer : " << this->singer << endl << endl;
	}

	void DeleteProduct()			// ��ǰ ����(���� + CD)
	{
		Product::DeleteProduct();
		delete[]title;
		delete[]singer;
	}

};

class CellPhone :public Product			// �޴��� Ŭ���� : ��ǰŬ���� ���
{
private:
	char* model;						// �𵨸�
	char* manufacturer;						// �귣���
public:
	CellPhone(int aidx, int aprice, char* adescription, char* amodel, char* amanufacturer)	// ��ǰ�߰�(���� + CellPhone)
		:Product(aidx, aprice, adescription)
	{
		model = new char[strlen(amodel) + 1];
		strcpy(model, amodel);

		manufacturer = new char[strlen(amanufacturer) + 1];
		strcpy(manufacturer, amanufacturer);
	}
	void getProduct()					// ��ǰ ���������(���� + �޴���)	
	{

		Product::getProduct();
		cout << " model : " << this->model << endl;
		cout << " manufacturer : " << this->manufacturer << endl << endl;
	}

	void DeleteProduct()			// ��ǰ ����(���� + �޴���)
	{
		Product::DeleteProduct();
		delete[]model;
		delete[]manufacturer;
	}
};

int main(void)
{
	vector<int> book_list;			// book ��ǰ��ȣ ����
	vector<int> cd_list;			// cd ��ǰ��ȣ ����
	vector<int> cellphone_list;		// CellPhone ��ǰ��ȣ ����

	static int idx = 0;
	Product* pobj[100];				// ��ǰ���(100��)
	while (1)
	{
		int Select_main;		// ���θ޴�
		cout << " +++++++++++++++ POS ++++++++++++++++" << endl << endl;
		cout << " 1. ��ǰ�߰�" << endl;
		cout << " 2. ��ǰ��ȸ" << endl;
		cout << " 3. ��ǰ����" << endl;
		cout << " 4. ��    ��" << endl << endl;
		cout << " ���� : ";
		cin >> Select_main;

		if (Select_main == 1)					// 1. ��ǰ�߰�
		{
			while (1)
			{
				system("cls");
				int Select_Add;
				cout << " +++++++++++++++ ��ǰ�߰� ++++++++++++++++" << endl << endl;
				cout << " 1. BOOK" << endl;
				cout << " 2. CD" << endl;
				cout << " 3. CELL PHONE" << endl;
				cout << " 4. �ڷΰ���" << endl << endl;
				cout << " ���� : ";
				cin >> Select_Add;

				if (Select_Add == 1)			// 1.1 book �߰�
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

				else if (Select_Add == 2)		// 1.2 cd �߰�
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

				else if (Select_Add == 3)		// 1.3 CellPhone �߰�
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

				else if (Select_Add == 4)		// 1.4 �ڷΰ���
				{
					system("cls");
					break;
				}

				else
				{
					system("cls");
					while (getchar() != '\n');
					cout << " �߸��� �Է°��Դϴ�." << endl;
				}
			}


		}

		else if (Select_main == 2)				// 2. ��ǰ��ȸ
		{
			while (1)
			{
				system("cls");
				int Select_view = 0;
				cout << " +++++++++++++++ ��ǰ��ȸ ++++++++++++++++" << endl << endl;
				cout << " 1. BOOK" << endl;
				cout << " 2. CD" << endl;
				cout << " 3. CELL PHONE" << endl;
				cout << " 4. �ڷΰ���" << endl << endl;
				cout << " ���� : ";
				cin >> Select_view;


				if (Select_view == 1)				// 2.1 book ������
				{
					system("cls");
					vector<int>::iterator iter_book;
					cout << " ----- < Book ��ϵ� ��ǰ��� > ----- " << endl << endl;
					for (iter_book = book_list.begin(); iter_book != book_list.end(); iter_book++)
					{
						pobj[*iter_book]->getProduct();
						cout << " ----------------------------------" << endl << endl;
					}
					system("pause");
					system("cls");
				}

				else if (Select_view == 2)			// 2.2 cd ������
				{
					system("cls");
					vector<int>::iterator iter_cd;
					cout << " ----- < CD ��ϵ� ��ǰ��� > ----- " << endl << endl;
					for (iter_cd = cd_list.begin(); iter_cd != cd_list.end(); iter_cd++)
					{
						pobj[*iter_cd]->getProduct();
						cout << " ----------------------------------" << endl << endl;
					}
					system("pause");
					system("cls");
				}

				else if (Select_view == 3)			// 2.3 CellPhone ������
				{
					system("cls");
					vector<int>::iterator iter_cellphone;
					cout << " ----- < CellPhone ��ϵ� ��ǰ��� > ----- " << endl << endl << endl;
					for (iter_cellphone = cellphone_list.begin(); iter_cellphone != cellphone_list.end(); iter_cellphone++)
					{
						pobj[*iter_cellphone]->getProduct();
						cout << " ----------------------------------" << endl << endl;
					}
					system("pause");
					system("cls");
				}

				else if (Select_view == 4)		// 2.4 �ڷΰ���
				{
					system("cls");
					break;
				}

				else
				{
					system("cls");
					while (getchar() != '\n');
					cout << " �߸��� �Է°��Դϴ�." << endl;
				}
			}

		}

		else if (Select_main == 3)				// 3.��ǰ����
		{
			while (1)
			{
				system("cls");
				int Select_delete = 0;
				cout << " +++++++++++++++ ��ǰ���� ++++++++++++++++" << endl << endl;
				cout << " 1. BOOK" << endl;
				cout << " 2. CD" << endl;
				cout << " 3. CELL PHONE" << endl;
				cout << " 4. �ڷΰ���" << endl << endl;
				cout << " ���� : ";
				cin >> Select_delete;

				if (Select_delete == 1)					// 3.1 book ����
				{
					system("cls");
					int Check_find = 0;
					int Delete_Product = 0;
					vector<int>::iterator iter_book;

					for (iter_book = book_list.begin(); iter_book != book_list.end(); iter_book++)
					{
						pobj[*iter_book]->getProduct();
					}

					cout << " �����ϰ��� �ϴ� ��ǰ ��ȣ�� �Է��ϼ��� :";
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
							cout << Delete_Product+1 << " �� ��ǰ �����Ǿ����ϴ�." << endl;
							system("pause");
							break;
						}
					}
					if (Check_find == 0)
					{
						cout << " �ش��ǰ�� ã���� �����ϴ�." << endl;
						system("pause");
					}

				}

				else if (Select_delete == 2)			// 3.2 cd ����
				{
					system("cls");
					int Check_find = 0;
					int Delete_Product = 0;
					vector<int>::iterator iter_cd;

					for (iter_cd = cd_list.begin(); iter_cd != cd_list.end(); iter_cd++)
					{
						pobj[*iter_cd]->getProduct();
					}

					cout << " �����ϰ��� �ϴ� ��ǰ ��ȣ�� �Է��ϼ��� :";
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
							cout << Delete_Product+1 << " �� ��ǰ �����Ǿ����ϴ�." << endl;
							system("pause");
							break;
						}
					}

					if (Check_find == 0)
					{
						cout << " �ش��ǰ�� ã���� �����ϴ�." << endl;
						system("pause");
					}
				}

				else if (Select_delete == 3)			// 3.3 cellPhone ����
				{
					system("cls");
					int Check_find = 0;
					int Delete_Product = 0;
					vector<int>::iterator iter_cellphone;

					for (iter_cellphone = cellphone_list.begin(); iter_cellphone != cellphone_list.end(); iter_cellphone++)
					{
						pobj[*iter_cellphone]->getProduct();
					}

					cout << " �����ϰ��� �ϴ� ��ǰ ��ȣ�� �Է��ϼ��� :";
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
							cout << Delete_Product+1 << " �� ��ǰ �����Ǿ����ϴ�." << endl;
							system("pause");
							break;
						}
					}
					if (Check_find == 0)
					{
						cout << " �ش��ǰ�� ã���� �����ϴ�." << endl;
						system("pause");
					}
				}

				else if (Select_delete == 4)			// 3.4 �ڷΰ���
				{
					system("cls");
					break;
				}

				else
				{
					while (getchar() != '\n');
					cout << " �߸��� �Է°��Դϴ�." << endl;
				}
			}
		}

		else if (Select_main == 4)						// 4.���α׷�����
		{
			exit(1);
		}

		else
		{
			system("cls");
			while (getchar() != '\n');
			cout << " �߸��� �Է°��Դϴ�." << endl;
		}
	}

	return 0;
}