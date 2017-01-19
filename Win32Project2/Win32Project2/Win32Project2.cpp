// Win32Project2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Windows.h"
#include <iostream>

using namespace std;

typedef int (*Func)(int x, int y);

int main()
{
	HMODULE hDll =LoadLibrary(_T("Y:\\Documents\\Code\\Socket\\Win32Project1\\Release\\Win32Project1.dll"));
	if (!hDll) {
		printf("error");
	}
	else {
		printf("ookk\r\n");
	}

	Func f = (Func)GetProcAddress(hDll, "add");
	if (!f) {
		printf("load error");
	}
	else {
		printf("load success");
		cout << endl << f << endl;
	}


	cout << "Result: 1+2=" << f(1, 2) << endl;

	FreeLibrary(hDll);

	char a[126];

	cin >> a;

	Beep(1,10000);


    return 0;
}

