// ServerDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Socket.h"
#include "ServerDialog.h"
#include "afxdialogex.h"


// ServerDialog �Ի���

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


// ServerDialog ��Ϣ�������
