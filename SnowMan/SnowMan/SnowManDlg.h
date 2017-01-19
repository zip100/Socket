
// SnowManDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Core.h"

// CSnowManDlg �Ի���
class CSnowManDlg : public CDialogEx
{
// ����
public:
	CSnowManDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNOWMAN_DIALOG };
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
	afx_msg LRESULT DisplayResult(WPARAM wParam, LPARAM lParam);//�Զ�����Ϣ
	DECLARE_MESSAGE_MAP()
public:
	Core* m_Core;
	void initMessageList();
	void InsertMessage(CString, CString);

	CListCtrl message_list;
};
