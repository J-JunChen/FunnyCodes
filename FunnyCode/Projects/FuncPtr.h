#pragma once
#include<iostream>
using namespace std;

// ���ֺ���ָ�붨�巽��
int (*pa)(int, int); // ��ֱ������ָ�����
typedef int (*Pb)(int, int); // ����ָ������
using Pc = int(*)(int, int); // ��ֱ�۵ı��ַ���

int add(int a, int b) {
	return a + b;
}

void TestFuncPtr() 
{
	pa = add;
	Pb pb = add;
	Pc pc = add;
	cout << "Normal : " << pa(1, 1) << endl;
	cout << "typedef: " << pb(1, 1) << endl;
	cout << "Using  : " << pc(1, 1) << endl;
}