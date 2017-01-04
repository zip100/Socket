// ServerDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Socket.h"
#include "ServerDialog.h"
#include "afxdialogex.h"


// ServerDialog 对话框

IMPLEMENT_DYNAMIC(ServerDialog, CDialogEx)

ServerDialog::ServerDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SERVER, pParent)
{

}

ServerDialog::~ServerDialog()
{
}

void ServerDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServerDialog, CDialogEx)
END_MESSAGE_MAP()


// ServerDialog 消息处理程序
