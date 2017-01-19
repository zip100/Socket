
// SocketDlg.h : ͷ�ļ�
//

#pragma once
#include "ServerDialog.h"
#include "ClinetDialog.h"
#include "afxcmn.h"
#include "Net.h"

// CSocketDlg �Ի���
class CSocketDlg : public CDialogEx
{
// ����
public:
	CSocketDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOCKET_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl my_tab;
	ServerDialog serverDialog;
	ClinetDialog clinetDialog;
	CRect tabRect;
};
