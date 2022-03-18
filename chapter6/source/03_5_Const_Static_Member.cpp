#include <iostream>
#pragma warning(disable:4996)

// 03_5 Const Static 멤버
// 

using namespace std;

class CountryArea
{
public:
	const static int RUSSIA			= 1707540;
	const static int CANADA			= 998467;
	const static int CHINA			= 957290;
	const static int SOUTH_KOREA	= 9922;
	
};


int main(void)
{
	cout << "러시아의 면적 : " << CountryArea::RUSSIA << "km" << endl;
	cout << "캐나다의 면적 : " << CountryArea::CANADA << "km" << endl;
	cout << "중국의 면적 : " << CountryArea::CHINA << "km" << endl;
	cout << "한국의 면적 : " << CountryArea::SOUTH_KOREA << "km" << endl;

	// * 출력결과 *
	// 러시아의 면적 : 1707540km
	// 캐나다의 면적 : 998467km
	// 중국의 면적 : 957290km
	// 한국의 면적 : 9922km


	return 0;
}