
// SnowMan.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSnowManApp: 
// �йش����ʵ�֣������ SnowMan.cpp
//

class CSnowManApp : public CWinApp
{
public:
	CSnowManApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSnowManApp theApp;