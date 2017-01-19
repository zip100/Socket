
// SnowManDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Core.h"

// CSnowManDlg 对话框
class CSnowManDlg : public CDialogEx
{
// 构造
public:
	CSnowManDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNOWMAN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT DisplayResult(WPARAM wParam, LPARAM lParam);//自定义消息
	DECLARE_MESSAGE_MAP()
public:
	Core* m_Core;
	void initMessageList();
	void InsertMessage(CString, CString);

	CListCtrl message_list;
};
