// ClinetDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Socket.h"
#include "ClinetDialog.h"
#include "afxdialogex.h"


// ClinetDialog �Ի���

IMPLEMENT_DYNAMIC(ClinetDialog, CDialogEx)

ClinetDialog::ClinetDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CLINET, pParent)
{

}

ClinetDialog::~ClinetDialog()
{
}

void ClinetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ClinetDialog, CDialogEx)
END_MESSAGE_MAP()


// ClinetDialog ��Ϣ�������
