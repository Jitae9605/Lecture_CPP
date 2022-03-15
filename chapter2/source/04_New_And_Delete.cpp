#include <iostream>
#include <cstring>
#include <cstdlib>

#pragma warning(disable:4996)
using namespace std;

// 4. malloc/free�� ��ü�ϴ� new/delete

// 1)
char* MakeStrAdr(int len)
{
	// char*str = (char*)malloc(sizeof(char)*len);
	char* str = new char[len];

	
	// int��				=> int * a = new int;
	// double��			=> double * b = new double;
	// int���迭			=> int * c = new int[3];
	// double���迭		=> double * d = new double[3];

	return str;
}

// )2
class Simple
{
public:
	Simple()
	{
		cout << "I'm simple constructor!" << endl;
	}
};

int main(void)
{
	std::cout << "------------ < 1) new & delete  > ----------------" << std::endl;
	// 1) new & delete

	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;

	//free(str);
	delete []str;	// int��				=> delete a;
					// double��			=> delete b;
					// int���迭			=> delete []c;
					// double���迭		=> delete []d;
				

	// * ��°�� *
	// I am so happy~

	std::cout << "------------ < 2) New Object  > ----------------" << std::endl;
	// 2) New Object
	// �����ϰԸ� ���ϸ� class�� ������ ����ü�� �����ص� �����ϴ�(������������)

	cout << "case1 : ";
	Simple* sp1 = new Simple;

	cout << "case2 : ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple)*1);

	cout << endl << "end of main" << endl;
	delete sp1;
	free(sp2);

	// * ��°�� *
	// case1: I'm simple constructor!
	// case2 :
	// end of main

	return 0;
}
