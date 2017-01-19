
// SocketDlg.h : 头文件
//

#pragma once
#include "ServerDialog.h"
#include "ClinetDialog.h"
#include "afxcmn.h"
#include "Net.h"

// CSocketDlg 对话框
class CSocketDlg : public CDialogEx
{
// 构造
public:
	CSocketDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOCKET_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
