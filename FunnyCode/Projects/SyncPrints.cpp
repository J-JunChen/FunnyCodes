/// <summary>
/// 多线程交替输出
/// </summary>
#include<iostream>
#include<windows.h>
#include<mutex>
#include<condition_variable>
using namespace std;

const int Len = 10;
const int Start = 1, End = 10;
const int SleepTime = 50;

mutex mtxs[Len];
condition_variable cvs[Len];

void func(int idx) {
	unique_lock locker(mtxs[idx]);
	int next = (idx + 1) % Len;
	for (int i = Start; i <= End; i++) {
		cout << i << endl;
		cvs[next].notify_one();
		cvs[idx].wait(locker);
	}
	cvs[next].notify_one();
}

int main()
{
	thread ts[Len];
	for (int i = 0; i < Len; i++) {
		ts[i] = thread(func, i);
		Sleep(SleepTime);
	}
	for (int i = 0; i < Len; i++)
		ts[i].join();
}