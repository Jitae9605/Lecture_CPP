#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 2. 배열클래스

class bouondChaeckIntArray
{
private:
	int* arr;
	int arrlen;

public:
	bouondChaeckIntArray(int len) :arrlen(len)
	{
		arr = new int[len];
	}

	int& operator[] (int idx)							// []연산자 오버로딩
	{
		if (idx < 0 || idx >= arrlen)		// 에러처리 - 배열이상을 출력하면 출력되던 쓰레기값 출력을 대체
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	~bouondChaeckIntArray()
	{
		delete[]arr;
	}
};

int main(void)
{
	bouondChaeckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;	
	for (int i = 0; i < 6; i++)		// 0 ~ 4까지 출력후 5는 없으므로 에러처리 진행
	{
		cout << arr[i] << endl;
	}

	// * 출력결과 *
	// 11
	// 22
	// 33
	// 44
	// 55
	// Array index out of bound exception

	return 0;
}