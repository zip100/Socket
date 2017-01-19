// ServerDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Socket.h"
#include "ServerDialog.h"
#include "afxdialogex.h"
#include "Net.h"

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
	DDX_Control(pDX, IDC_PORT, my_port);
	DDX_Control(pDX, IDC_BUTTON2, listenBtn);
	DDX_Control(pDX, IDC_LIST3, showBox);
	DDX_Control(pDX, IDC_BUTTON3, stopBtn);
}


BEGIN_MESSAGE_MAP(ServerDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ServerDialog::OnBnClickedButton1)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, &ServerDialog::OnIpnFieldchangedIpaddress1)
	ON_BN_CLICKED(IDC_BUTTON2, &ServerDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ServerDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// ServerDialog 消息处理程序


void ServerDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("ok"));
}


void ServerDialog::OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}



UINT ServerDialog::ThreadFun(LPVOID pParam) {

	if (!AfxSocketInit())
	{
		return 1;
	}

	ServerDialog *a = (ServerDialog*)pParam;

	CSocket serverSocket;

	a->aSocket.Accept(serverSocket);
	


	OutputDebugString(_T("i am from  thread"));
	return 0;
}


void ServerDialog::OnBnClickedButton2()
{
	show(_T("listen."));
	// TODO: 在此添加控件通知处理程序代码
	CString port;
	my_port.GetWindowTextW(port);

	if (!AfxSocketInit())
	{
		show(_T("Socket 初始化错误"));
		return;
	}
	show(_T("Socket 初始化成功"));

	if (!aSocket.Socket()) {
	}

	BOOL bOptVal = TRUE;
	int bOptLen = sizeof(BOOL);
	//设置Socket的选项, 解决10048错误必须的步骤  
	aSocket.SetSockOpt(SO_REUSEADDR, (void *)&bOptVal, bOptLen, SOL_SOCKET);

	//绑定  

	aSocket.Bind(0);

	
	OutputDebugString(port);


	// 监听
	if (!aSocket.Listen()) {
		show(_T("端口监听错误"));
	}
	else {
		show(_T("端口监听中..."));
	}

	stopBtn.EnableWindow(true);

	::AfxBeginThread(ThreadFun, this);

}

void ServerDialog::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	aSocket.Close();
	listenBtn.EnableWindow(true);
	stopBtn.EnableWindow(false);
	show(_T("Socket 关闭成功"));
}


void ServerDialog::show(CString str) {
	showBox.InsertString(showBox.GetCount(), str);
}
