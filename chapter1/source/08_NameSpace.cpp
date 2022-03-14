#include<iostream>

// 8.�̸�����(Name Space)
// �̸��� �ٿ����� �����̴�.
// �ٸ� ������ ����� �̸��� ���δ��� �װ��� �Լ����� �����ϴ°�

// 1)�Լ�
namespace BestComImpl
{
	void SimpleFunc_1(void)
	{
		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}

	void SimpleFunc_5(void)
	{
		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}
	// �̷��� �ѹ��� �����ϴ°͵� ����

}

namespace ProgComImpl
{
	void SimpleFunc_1(void)
	{
		std::cout << "ProgCom�� ������ �Լ�" << std::endl;
	}
}

// 2)�Լ�
namespace BestComImpl
{
	void SimpleFunc_2(void);
}

namespace ProgComImpl
{
	void SimpleFunc_2(void);
}

// 3)�Լ�
namespace BestComImpl
{
	void SimpleFunc_3(void);
}

namespace BestComImpl
{
	void PrettyFunc_3(void);
}

namespace ProgComImpl
{
	void SimpleFunc_3(void);
}

int main(void)
{
	std::cout << "------------ < 1) ���ӽ����̽��� �⺻����  > ----------------" << std::endl;
	// 1) ���ӽ����̽��� �⺻����
	// ���� �̸��� �Ű������� �Լ������� ���ӽ����̽��� ���� �Լ��� ������
	BestComImpl::SimpleFunc_1();
	ProgComImpl::SimpleFunc_1();

	// * ��°�� * 
	// BestCom�� ������ �Լ�
	// ProgCom�� ������ �Լ�

	std::cout << "------------ < 2) ���ӽ����̽� �Լ��� ����� ����  > ----------------" << std::endl;
	// 2) ���ӽ����̽� �Լ��� ����� ����
	// ���Ǵ� ���(ȣ��)�� ���� �տ� ���ӽ����̽��� �ٿ��� ���Ǹ� �ؾ��ϰ� ������ ���ӽ����̽� ���ο��� �����ؾ��Ѵ�.
	BestComImpl::SimpleFunc_2();
	ProgComImpl::SimpleFunc_2();

	// * ��°�� * 
	// BestCom�� ������ �Լ�
	// ProgCom�� ������ �Լ�

	std::cout << "------------ < 3) ������ ���ӽ����̽����� �Լ��� ���  > ----------------" << std::endl;
	// 3) ������ ���ӽ����̽����� �Լ��� ���
	// ������ ���ӽ����̽� ���� �ٸ� �Լ��� ȣ���ϴ� ��쿡�� ���ӽ����̽��� ���� �����ʾƵ� �ȴ�.
	BestComImpl::SimpleFunc_3();

	// * ��°�� * 
	// BestCom�� ������ �Լ�
	// So Pretty!!
	// ProgCom�� ������ �Լ�

	// ** �̸������� ��ø�� �����ϴ�
	// ex) �̸�����1{�̸�����2{�Լ���();}}
	// �׷���� �Լ��� ����� �̸�����1::�̸�����2::�Լ���();���� ȣ��

	return 0;
}

// 2) �Լ�
void BestComImpl::SimpleFunc_2(void)
{
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
}

void ProgComImpl::SimpleFunc_2(void)
{
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}


// 3) �Լ�
void BestComImpl::SimpleFunc_3(void)
{
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
	PrettyFunc_3();										// ���� �̸��������� �Լ�
	ProgComImpl::SimpleFunc_3();							// �ٸ� �̸��������� �Լ�
}

void BestComImpl::PrettyFunc_3(void)
{
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc_3(void)
{
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}
