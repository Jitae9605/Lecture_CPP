#include<iostream>
#include<vector>
using namespace std;

// 2.vector�� ���뼺 = ũ�Ⱑ �ڵ����� ������.(strlen�� �ڵ���)
// ũ���� ������ ����.

int main(void)
{
	vector<int> v;										// vector����

	// 1) v.push_back()
	for (int i = 0; i < 20; i++)						// v[0] ~ v[19] ���� 1 ~ 20�� ���� �ִ´�
	{
		v.push_back(i + 1);								// v�� �� �ڿ� ���� �ִ´�
		cout << "v[" << i << "] : " << v[i] << endl;
	}

	// 2) v.size()
	//for (int i = 0; i < v.size(); i++)					
	//{
	//	v.push_back(i + 1);								// �ǵڿ� �����Ƿ� v[	20] ���� v[����] ���� 1 ~ ������ ���� �ִ´�.					
	//	cout << "v[" << i << "] : " << v[i] << endl;
	//}

	// 3) iter, v.begin, v.end
	//vector<int>::iterator iter;							// [iter = ������], [v.begin() = v�� �����ּ�], [v.end() = v�� �� �ּ� + 1]
	//for (iter = v.begin(); iter != v.end(); iter++)		// ���� �Էµ� v�� ó��(v.begin()) ���� v�� ��(v.end())������ ���� ���
	//{
	//	cout << *iter << endl;
	//}

	// 4) verter<string>
	vector<string>s;
	s.push_back("tiger");
	s.push_back("lion");
	s.push_back("elephant");
	s.push_back("cow");

	vector<string>::iterator iter;						// [iter = ������], [v.begin() = v�� ���� �ּ�], [v.end() = v�� �� �ּ� + 1]

	cout << endl << "���� ��" << endl << endl;
	for (iter = s.begin(); iter != s.end(); iter++)		// ���� �Էµ� v�� ó��(v.begin()) ���� v�� ��(v.end())���� �ݺ�
	{
		cout << *iter << endl;
	}

	for (iter = s.begin(); iter != s.end(); iter++)		// ���� �Էµ� v�� ó��(v.begin()) ���� v�� ��(v.end())���� �ݺ�
	{
		if (*iter == "lion")
		{
			s.erase(iter);								//s.erase(�ּ�) = �ش� �ּ��� ��Ұ� ���� �� �迭 ����(�����κ� �� �迭 �Ųٱ�)
			break;
		}
	}

	cout << endl << "���� ��" << endl << endl;
	for (iter = s.begin(); iter != s.end(); iter++)		// ���� �Էµ� v�� ó��(v.begin()) ���� v�� ��(v.end())���� �ݺ�
	{
		cout << *iter << endl;							// erase�Ǹ� �ڵ����� v�� ��������
	}

	// 5) s.front(), s.back()
	cout << s.front() << endl;							// [s.front() = ù��° ����� ��]
	cout << s.back() << endl;							// [s.back() = ������ ����� ��]

	return 0;
}