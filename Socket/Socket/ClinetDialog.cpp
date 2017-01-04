// ClinetDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Socket.h"
#include "ClinetDialog.h"
#include "afxdialogex.h"


// ClinetDialog 对话框

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


// ClinetDialog 消息处理程序
