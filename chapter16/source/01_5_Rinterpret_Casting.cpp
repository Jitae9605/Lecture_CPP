#include<iostream>
using namespace std;

// 1_5.리인터프리트 캐스팅
// reinterpret_casting =  모든 포인터 형변환 허용
//  -> 포인터를 대상으로하는, 포인터와 관련있는 모든 종류/유형의 형변환을 허용

int main(void)
{
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num);

	for (int i = 0; i < sizeof(num); i++)
		cout << static_cast<int>(*(ptr + i)) << endl;

	return 0;
}