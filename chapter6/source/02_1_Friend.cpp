#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 2_1. friend 클래스 형식/선언
// a가 b를 firend로 선언을 하면 b는 a의 private에 접근이 가능하다
// 선언은 단방향이다. 

using namespace std;

class girl;					// 사전선언 ( boy에서 girl을 썼는데 girl이 boy 밑에 있어 인식을 못함 )

class boy
{
private:
	int height;
	friend class girl;					// girl을 friend로 선언
public:
	boy(int len):height(len)
	{ }
	void ShowYourFriendInfo(girl& frn);
};

class girl
{
private: 
	char phNum[20];
public:
	girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(boy& frn);
	friend class boy;					// boy를 friend로 선언

};

void boy::ShowYourFriendInfo(girl& frn)
{
	cout << "Her phone number : " << frn.phNum << endl;
}

void girl::ShowYourFriendInfo(boy& frn)
{
	cout << "His Height : " << frn.height << endl;

}

int main()
{
	boy boy(170);
	girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);


	// * 출력결과 *
	// Her phone number : 010-1234-5678
	// His Height : 170
	return 0;
}