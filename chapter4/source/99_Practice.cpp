#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class Ctime
{
private:
	int hout;			// �ð�
	int min;			// ��
	int sec;			// ��

public:
	Ctime(int ahout, int amin, int asec)	// ������
		:hout(ahout), min(amin), sec(asec)	// �������� �Ű������� ���� ����鿡 ����
	{
		//cout << "����Ʈ ������" << endl;
	}

	//void SetTime(int ahout, int amin, int asec) // �ð�����
	//{
	//	hout = ahout;
	//	min = amin;
	//	sec = asec;

	//}

	void getTime()								// �Է��� �ð����
	{
		cout << "���� �ð��� " << hout << "�� " << min << "�� " << sec << "�� �Դϴ�." << endl << endl;
	}
};

int main(void)
{
	Ctime t(11, 20, 50);						// Ŭ���� �����ڿ� ������
	//	t.SetTime(11, 20, 50);					// ��ü�� �ɹ��� ���ο�
	t.getTime();								// ��ü ���

	// * ��� ��� *
	// ���� �ð��� 11�� 20�� 50�� �Դϴ�.

	return 0;
}