#include <iostream>
#include <cstring>
#include <cstdlib>

#pragma warning(disable:4996)
using namespace std;

// 4. malloc/free를 대체하는 new/delete

// 1)
char* MakeStrAdr(int len)
{
	// char*str = (char*)malloc(sizeof(char)*len);
	char* str = new char[len];

	
	// int형				=> int * a = new int;
	// double형			=> double * b = new double;
	// int형배열			=> int * c = new int[3];
	// double형배열		=> double * d = new double[3];

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
	delete []str;	// int형				=> delete a;
					// double형			=> delete b;
					// int형배열			=> delete []c;
					// double형배열		=> delete []d;
				

	// * 출력결과 *
	// I am so happy~

	std::cout << "------------ < 2) New Object  > ----------------" << std::endl;
	// 2) New Object
	// 간단하게만 말하면 class는 일종의 구조체로 생각해도 무방하다(현시점에서는)

	cout << "case1 : ";
	Simple* sp1 = new Simple;

	cout << "case2 : ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple)*1);

	cout << endl << "end of main" << endl;
	delete sp1;
	free(sp2);

	// * 출력결과 *
	// case1: I'm simple constructor!
	// case2 :
	// end of main

	return 0;
}
