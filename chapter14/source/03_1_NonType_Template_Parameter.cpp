#include<iostream>
using namespace std;

// 3. 템플릿 인자
// 3_1. 배열길이를 매개변수에 정수로 전달해주는것에 무슨 문법적 의미가 있는지 알아보자

template <typename T, int len>
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
	SimpleArray<int, 5> i5arr1;
	for (int i = 0; i < 5; i++)
		i5arr1[i] = i * 10;

	SimpleArray<int, 5> i5arr2;
	i5arr2 = i5arr1;
	for (int i = 0; i < 5; i++)
		cout << i5arr2[i] << ", ";
	cout << endl;

	SimpleArray<int, 7> i7arr1;
	for (int i = 0; i < 7; i++)
		i7arr1[i] = i * 10;

	SimpleArray<int, 7> i7arr2;
	i7arr2 = i7arr1;
	for (int i = 0; i < 7; i++)
		cout << i7arr2[i] << ", ";
	cout << endl;

	// * 출력결과 *
	// 0, 10, 20, 30, 40,
	// 0, 10, 20, 30, 40, 50, 60,

	return 0;
}