#include <iostream>
#include"02_1_Point.h"
#include"02_3_Rectangle.h"
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	Point pos1;
	if (!pos1.InitMembers(-2, 4))
		cout << "�ʱ�ȭ ����" << endl;
	if (!pos1.InitMembers(2, 4))
		cout << "�ʱ�ȭ ����" << endl;

	Point pos2;
	if (!pos2.InitMembers(5, 9))
		cout << "�ʱ�ȭ ����" << endl;

	Rectangle rec;
	if (!rec.InitMembers(pos2, pos1))
		cout << "���簢�� �ʱ�ȭ ����" << endl;

	if (!rec.InitMembers(pos1, pos2))
		cout << "���簢�� �ʱ�ȭ ����" << endl;
	
	rec.ShowRecInfo();

	// * ��°�� *
	// ��� ������ �� ����
	// �ʱ�ȭ ����
	// �߸��� ��ġ���� ����
	// ���簢�� �ʱ�ȭ ����
	// �� ��� : [2, 4]
	// �� �ϴ� : [5, 9]

	return 0;

}