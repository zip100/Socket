// Win32Project1.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

#ifndef LIB_H
#define LIB_H
extern "C" int __declspec(dllexport)add(int x, int y);
#endif

int add(int x, int y)
{
	return x + y;
}
