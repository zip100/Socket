#pragma once


// ClinetDialog �Ի���

class ClinetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ClinetDialog)

public:
	ClinetDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ClinetDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLINET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
