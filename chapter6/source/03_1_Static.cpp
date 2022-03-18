#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 3. static의 이용
// static의 특성
// 선언된 클래스의 모든 객체가 공유한다
// public으로 선언되면 클래스의 이름을 통해 호출이 가능하다.
// 객체의 멤버로 존재하는 것이 아니다

using namespace std;

void Counter()
{
	static int cnt;								// static으로 선언했으므로 함수가 끝나도 cnt가 여전히 살아있다
	cnt++;
	cout << "Current cnt : " << cnt << endl;
}



int main(void)
{
	for (int i = 0; i < 10; i++)
		Counter();					// cnt가 static이 아니면 cnt는 호출때마다 사라지고 새로 cnt가 생성 
									//		=> Current cnt : 1 만 계속 출력

	// * 출력결과 *
	// Current cnt : 1
	// Current cnt : 2
	// Current cnt : 3
	// Current cnt : 4
	// Current cnt : 5
	// Current cnt : 6
	// Current cnt : 7
	// Current cnt : 8
	// Current cnt : 9
	// Current cnt : 10

	return 0;
}