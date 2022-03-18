#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 2_1. friend Ŭ���� ����/����
// a�� b�� firend�� ������ �ϸ� b�� a�� private�� ������ �����ϴ�
// ������ �ܹ����̴�. 

using namespace std;

class girl;					// �������� ( boy���� girl�� ��µ� girl�� boy �ؿ� �־� �ν��� ���� )

class boy
{
private:
	int height;
	friend class girl;					// girl�� friend�� ����
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
	friend class boy;					// boy�� friend�� ����

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


	// * ��°�� *
	// Her phone number : 010-1234-5678
	// His Height : 170
	return 0;
}