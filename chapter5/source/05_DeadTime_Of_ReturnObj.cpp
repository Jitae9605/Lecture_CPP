#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 6. 반환객체의 소멸시점
// 

using namespace std;

class Sosimple
{
private:
	int num;

public:
	Sosimple(int n) :num(n)
	{
		cout << "New Object : " << this << endl;
	}

	Sosimple(const Sosimple& copy) :num(copy.num)		// 복사생성자의 디폴트 - 따로 언급안해도 원래있음(숨겨져서 안보일뿐)
	{
		cout << "New Copy Object : " << this << endl;
	}

	~Sosimple()
	{
		cout << "Destroy Object : " << this << endl;
	}
};

Sosimple simplefuncobj(Sosimple ob)
{
	cout << "Parm ADR : " << &ob<<endl;
	return ob;							// 임시객체
}

int main(void)
{
	Sosimple obj(7);
	simplefuncobj(obj);
	
	cout << endl;

	Sosimple tempRef = simplefuncobj(obj);
	cout << "Return Obj" << &tempRef << endl;

	// * 출력결과 *
	// New Object : 0053F8EC			// 40행 : obj생성
	// New Copy Object : 0053F7D4		// 32행의 함수호출로 매개변수 ob생성
	// Parm ADR : 0053F7D4				// 함수 내부 출력문(ob의 주소값)
	// New Copy Object : 0053F808		// return ob 반환에 의한 임시객체생성
	// Destroy Object : 0053F7D4		// 매개변수 ob소멸
	// Destroy Object : 0053F808		// 반환에 의해 생성된 임시객체 소멸
	// 
	// New Copy Object : 0053F7D4		// 함수호출로 매개변수 ob생성
	// Parm ADR : 0053F7D4				// 함수내부 출력문(ob의 주소값)
	// New Copy Object : 0053F8E0		// return ob 반환에 의한 임시객체 생성
	// Destroy Object : 0053F7D4		// 매개변수 ob소멸
	// Return Obj0053F8E0				// tempRef의 주소값이 반환에의한 임시객체와 같음 == 반환에 의한 임시객체의 주소값을 tempRef가 받은것(즉, 참조하고있음)
	// Destroy Object : 0053F8E0		// tempRef가 참조하는 임시객체 소멸 ( => tempRef 도 소멸된 것과 같다 )
	// Destroy Object : 0053F8EC		// obj소멸

	// !!! 주의 !!!
	// 실제로는 tempRef는 생성되는게 아니라 반환에 의해 생성된 임시객체에 tempRef의 이름을 할당한 것 !!!
	return 0;
}