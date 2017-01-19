#pragma once


// ClinetDialog 对话框

class ClinetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ClinetDialog)

public:
	ClinetDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ClinetDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLINET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
