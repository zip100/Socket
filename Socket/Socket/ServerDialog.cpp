// ServerDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Socket.h"
#include "ServerDialog.h"
#include "afxdialogex.h"
#include "Net.h"

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


// ServerDialog ��Ϣ�������


void ServerDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("ok"));
}


void ServerDialog::OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString port;
	my_port.GetWindowTextW(port);

	if (!AfxSocketInit())
	{
		show(_T("Socket ��ʼ������"));
		return;
	}
	show(_T("Socket ��ʼ���ɹ�"));

	if (!aSocket.Socket()) {
	}

	BOOL bOptVal = TRUE;
	int bOptLen = sizeof(BOOL);
	//����Socket��ѡ��, ���10048�������Ĳ���  
	aSocket.SetSockOpt(SO_REUSEADDR, (void *)&bOptVal, bOptLen, SOL_SOCKET);

	//��  

	aSocket.Bind(0);

	
	OutputDebugString(port);


	// ����
	if (!aSocket.Listen()) {
		show(_T("�˿ڼ�������"));
	}
	else {
		show(_T("�˿ڼ�����..."));
	}

	stopBtn.EnableWindow(true);

	::AfxBeginThread(ThreadFun, this);

}

void ServerDialog::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	aSocket.Close();
	listenBtn.EnableWindow(true);
	stopBtn.EnableWindow(false);
	show(_T("Socket �رճɹ�"));
}


void ServerDialog::show(CString str) {
	showBox.InsertString(showBox.GetCount(), str);
}
