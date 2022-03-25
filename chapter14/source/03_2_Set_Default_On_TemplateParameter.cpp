#include<iostream>
using namespace std;

// 3_2. 탬플릿 매개변수에 디폴트값 지정

template <typename T=int, int len=7>			// default값 지정
class SimpleArray
{
private:
	T arr[len];
public:
	T& operator[] (int idx) { return arr[idx]; }
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
	{
		for (int i = 0; i < len; i++)
			arr[i] = ref.arr[i];
		return *this;
	}
};

int main(void)
{
	SimpleArray<> arr;
	for (int i = 0; i < 7; i++)
		arr[i] = i +1;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;


	// * 출력결과 *
	// 1 2 3 4 5 6 7


	return 0;
}