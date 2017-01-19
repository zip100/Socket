
// BinaryFileDlg.h : 头文件
//

#pragma once

#include "Resource.h"
#include "afxcmn.h"

// CBinaryFileDlg 对话框
class CBinaryFileDlg : public CDialogEx
{
// 构造
public:
	CBinaryFileDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BINARYFILE_DIALOG };
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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelectFile();
	afx_msg void OnEnChangePath();
	afx_msg void OnBnClickedSaveBtn();
	afx_msg void OnEnChangeSavePath();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedRun();
	CProgressCtrl my_process;
};
