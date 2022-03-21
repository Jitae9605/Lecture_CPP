#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

// Is - A ���踦 ���� ��� ���� 2��
// EBook p313

class Book
{
private:
	char* title;
	char* isbn;
	int price;

public:
	Book(const char* atitle, const char* aisbn, int aprice) : price(aprice)
	{
		title = new char[strlen(atitle) + 1];
		strcpy(title, atitle);
		isbn = new char[strlen(aisbn) + 1];
		strcpy(isbn, aisbn);
	}
	void ShowBookInfo()
	{
		cout << "���� : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "���� : " << price << endl;
	}

};

class EBook :public Book
{
private:
	char* DRMkey;

public:
	EBook(const char* atitle, const char* aisbn, int aprice, const char* aDRMkey) : Book(atitle,aisbn,aprice)
	{
		DRMkey = new char[strlen(aDRMkey) + 1];
		strcpy(DRMkey, aDRMkey);
	}

	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "����Ű : " << DRMkey << endl;
	}


};

int main(void)
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9ww0i8kiw");
	ebook.ShowEBookInfo();

	// * ��°�� *
	// ���� : ���� C++
	// ISBN: 555 - 12345 - 890 - 0
	// ���� : 20000
	// 
	// ���� : ���� C++ ebook
	// ISBN : 555 - 12345 - 890 - 1
	// ���� : 10000
	// ����Ű : fdx9ww0i8kiw

	return 0;
}