#pragma once
#include<iostream>
using namespace std;

// ���ֺ���ָ�붨�巽��
static int (*pa)(int, int); // ��ֱ������ָ�����
typedef int (*FuncPtrPb)(int, int); // ����ָ������
using FuncPtrPc = int(*)(int, int); // ��ֱ�۵ı��ַ���

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