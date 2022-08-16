#pragma once
#include<iostream>
using namespace std;

// 三种函数指针定义方法
static int (*pa)(int, int); // 会直接生成指针变量
typedef int (*FuncPtrPb)(int, int); // 定义指针类型
using FuncPtrPc = int(*)(int, int); // 最直观的表现方法

static int add(int a, int b) {
	return a + b;
}

void TestFuncPtr() 
{
	pa = add;
	FuncPtrPb pb = add;
	FuncPtrPc pc = add;
	cout << "Normal : " << pa(1, 1) << endl;
	cout << "typedef: " << pb(1, 1) << endl;
	cout << "Using  : " << pc(1, 1) << endl;
}