
// BinaryFile.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBinaryFileApp: 
// �йش����ʵ�֣������ BinaryFile.cpp
//

class CBinaryFileApp : public CWinApp
{
public:
	CBinaryFileApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBinaryFileApp theApp;