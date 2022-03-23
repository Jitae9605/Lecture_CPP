#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 2_2 const함수를 이용한 오버로딩 (에러발생)

class bouondChaeckIntArray
{
private:
	int* arr;
	int arrlen;
	bouondChaeckIntArray(const bouondChaeckIntArray& arr) { }
	bouondChaeckIntArray& operator=(const bouondChaeckIntArray& arr) { }

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

	int GetArrLen() const { return arrlen; }

	~bouondChaeckIntArray()
	{
		delete[]arr;
	}
};

void ShowAllData(const bouondChaeckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
	{
		cout << ref[idx] << endl;
	}
}

int main(void)
{
	bouondChaeckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	ShowAllData(arr);

	// * 출력결과 *
	// 컴파일 에러 발생

	return 0;
}