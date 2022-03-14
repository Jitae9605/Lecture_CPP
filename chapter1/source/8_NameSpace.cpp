#include<iostream>

// 8.이름공간(Name Space)
// 이름을 붙여놓은 공간이다.
// 다른 공간을 만들고 이름을 붙인다음 그곳에 함수등을 정의하는것

// 1)함수
namespace BestComImpl
{
	void SimpleFunc_1(void)
	{
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}

	void SimpleFunc_5(void)
	{
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
	// 이렇게 한번에 선언하는것도 가능

}

namespace ProgComImpl
{
	void SimpleFunc_1(void)
	{
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

// 2)함수
namespace BestComImpl
{
	void SimpleFunc_2(void);
}

namespace ProgComImpl
{
	void SimpleFunc_2(void);
}

// 3)함수
namespace BestComImpl
{
	void SimpleFunc_3(void);
}

namespace BestComImpl
{
	void PrettyFunc_3(void);
}

namespace ProgComImpl
{
	void SimpleFunc_3(void);
}

int main(void)
{
	std::cout << "------------ < 1) 네임스페이스의 기본원리  > ----------------" << std::endl;
	// 1) 네임스페이스의 기본원리
	// 같은 이름과 매개변수의 함수이지만 네임스페이스를 통해 함수를 구분함
	BestComImpl::SimpleFunc_1();
	ProgComImpl::SimpleFunc_1();

	// * 출력결과 * 
	// BestCom이 정의한 함수
	// ProgCom이 정의한 함수

	std::cout << "------------ < 2) 네임스페이스 함수의 선언과 정의  > ----------------" << std::endl;
	// 2) 네임스페이스 함수의 선언과 정의
	// 정의는 사용(호출)과 같이 앞에 네임스페이스를 붙여서 정의를 해야하고 선언으 네임스페이스 내부에서 선언해야한다.
	BestComImpl::SimpleFunc_2();
	ProgComImpl::SimpleFunc_2();

	// * 출력결과 * 
	// BestCom이 정의한 함수
	// ProgCom이 정의한 함수

	std::cout << "------------ < 3) 동일한 네임스페이스내의 함수의 사용  > ----------------" << std::endl;
	// 3) 동일한 네임스페이스내의 함수의 사용
	// 동일한 네임스페이스 내의 다른 함수를 호출하는 경우에는 네임스페이스를 따록 적지않아도 된다.
	BestComImpl::SimpleFunc_3();

	// * 출력결과 * 
	// BestCom이 정의한 함수
	// So Pretty!!
	// ProgCom이 정의한 함수

	// ** 이름공간은 중첩이 가능하다
	// ex) 이름공간1{이름공간2{함수명();}}
	// 그럴경우 함수의 사용은 이름공간1::이름공간2::함수명();으로 호출

	return 0;
}

// 2) 함수
void BestComImpl::SimpleFunc_2(void)
{
	std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgComImpl::SimpleFunc_2(void)
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}


// 3) 함수
void BestComImpl::SimpleFunc_3(void)
{
	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc_3();										// 동일 이름공간내의 함수
	ProgComImpl::SimpleFunc_3();							// 다른 이름공간내의 함수
}

void BestComImpl::PrettyFunc_3(void)
{
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc_3(void)
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}
