#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1_2. ��ü�ȿ� ����Լ��� ������ �����ϴ°�2
// 01_1_Really_Memberfunc_Is_Under_Obj_1�� ���� �������� Ŭ������ �ƴ� ����ü�� ǥ���� ����� ��

typedef struct Data
{
	int data;
	void(*ShowData)(Data*);
	void (*Add)(Data*, int);
}Data;

void ShowData(Data*THIS) { cout << "Data : " << THIS->data << endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

int main(void)
{
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);


	// * ��°�� *
	// Data : 32		// 15 + 17	= 32
	// Data : 16		//  7 +  9	= 16
	return 0;
}