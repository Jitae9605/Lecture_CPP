#include<iostream>
#include<vector>
using namespace std;

// 2.vector의 유용성 = 크기가 자동으로 잡힌다.(strlen이 자동임)
// 크기의 지정이 없다.

int main(void)
{
	vector<int> v;										// vector선언

	// 1) v.push_back()
	for (int i = 0; i < 20; i++)						// v[0] ~ v[19] 까지 1 ~ 20을 각각 넣는다
	{
		v.push_back(i + 1);								// v의 맨 뒤에 값을 넣는다
		cout << "v[" << i << "] : " << v[i] << endl;
	}

	// 2) v.size()
	//for (int i = 0; i < v.size(); i++)					
	//{
	//	v.push_back(i + 1);								// 맨뒤에 넣으므로 v[	20] 부터 v[무한] 까지 1 ~ 무한을 각각 넣는다.					
	//	cout << "v[" << i << "] : " << v[i] << endl;
	//}

	// 3) iter, v.begin, v.end
	//vector<int>::iterator iter;							// [iter = 포인터], [v.begin() = v의 시작주소], [v.end() = v의 끝 주소 + 1]
	//for (iter = v.begin(); iter != v.end(); iter++)		// 현재 입력된 v의 처음(v.begin()) 부터 v의 끝(v.end())까지의 값을 출력
	//{
	//	cout << *iter << endl;
	//}

	// 4) verter<string>
	vector<string>s;
	s.push_back("tiger");
	s.push_back("lion");
	s.push_back("elephant");
	s.push_back("cow");

	vector<string>::iterator iter;						// [iter = 포인터], [v.begin() = v의 시작 주소], [v.end() = v의 끝 주소 + 1]

	cout << endl << "삭제 전" << endl << endl;
	for (iter = s.begin(); iter != s.end(); iter++)		// 현재 입력된 v의 처음(v.begin()) 부터 v의 끝(v.end())까지 반복
	{
		cout << *iter << endl;
	}

	for (iter = s.begin(); iter != s.end(); iter++)		// 현재 입력된 v의 처음(v.begin()) 부터 v의 끝(v.end())까지 반복
	{
		if (*iter == "lion")
		{
			s.erase(iter);								//s.erase(주소) = 해당 주소의 요소값 삭제 및 배열 정렬(삭제부분 빈 배열 매꾸기)
			break;
		}
	}

	cout << endl << "삭제 후" << endl << endl;
	for (iter = s.begin(); iter != s.end(); iter++)		// 현재 입력된 v의 처음(v.begin()) 부터 v의 끝(v.end())까지 반복
	{
		cout << *iter << endl;							// erase되면 자동으로 v가 땡겨져옴
	}

	// 5) s.front(), s.back()
	cout << s.front() << endl;							// [s.front() = 첫번째 요소의 값]
	cout << s.back() << endl;							// [s.back() = 마지막 요소의 값]

	return 0;
}