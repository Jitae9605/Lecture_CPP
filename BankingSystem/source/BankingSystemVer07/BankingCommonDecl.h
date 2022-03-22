/*
* BankingCommonDecl.h
* 작성자 : 이지태
*/


#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

const int NAME_LEN = 20;

// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 신용등급에 따른 이자율
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌종류
enum { NOMAL = 1, CREDIT = 2 };


#endif