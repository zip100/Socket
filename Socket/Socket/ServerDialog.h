#pragma once
#include "afxwin.h"
#include "afxsock.h"

// ServerDialog �Ի���

class ServerDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ServerDialog)

public:
	ServerDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ServerDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit my_port;
	CSocket aSocket;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	void show(CString);
	CButton listenBtn;
	CListBox showBox;
	CButton stopBtn;
	static UINT ThreadFun(LPVOID pParam);
};
