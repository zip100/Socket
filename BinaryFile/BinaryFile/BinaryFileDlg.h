
// BinaryFileDlg.h : ͷ�ļ�
//

#pragma once

#include "Resource.h"
#include "afxcmn.h"

// CBinaryFileDlg �Ի���
class CBinaryFileDlg : public CDialogEx
{
// ����
public:
	CBinaryFileDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BINARYFILE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
