#include<iostream>
using namespace std;

// 3_3 ����Ǯ��
// ����Ǯ�� = ���ܰ� ó�������ʾƼ� �Լ��� ȣ���� �������� ���ܵ����Ͱ� ���޵Ǵ� ����
// �̷� �̸��� ���� ������ �˾ƺ���

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "�����ڵ� : " << expn << endl;
	}


	// * ��°�� *
	// SiompleFuncOne(void)
	// SiompleFuncTwo(void)
	// SimpleFuncThree(void)
	// �����ڵ� : -1

	// �� �Լ� �Ʒ��κ��� end���������� ������� �ʴ´� 
	// -> ���ܰ� �߻����ڸ��� �ڿ��� ���� �����ϰ� throw�� ���� �ٷ� catch���� ������

	return 0;

	
}

void SimpleFuncOne(void)
{
	cout << "SiompleFuncOne(void)" << endl;
	SimpleFuncTwo();
	cout << "SimpleFuncOne end" << endl;
}

void SimpleFuncTwo(void)
{
	cout << "SiompleFuncTwo(void)" << endl;
	SimpleFuncThree();
	cout << "SimpleFuncTwo end" << endl;
}

void SimpleFuncThree(void)
{
	cout << "SimpleFuncThree(void)" << endl;
	throw - 1;
}

