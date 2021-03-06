
// BinaryFileDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BinaryFile.h"
#include "BinaryFileDlg.h"
#include "afxdialogex.h"
#include "fstream"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBinaryFileDlg 对话框



CBinaryFileDlg::CBinaryFileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BINARYFILE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBinaryFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, my_process);
}

BEGIN_MESSAGE_MAP(CBinaryFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SELECT_FILE, &CBinaryFileDlg::OnBnClickedSelectFile)
	ON_BN_CLICKED(IDC_SAVE, &CBinaryFileDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_RUN, &CBinaryFileDlg::OnBnClickedRun)
END_MESSAGE_MAP()


// CBinaryFileDlg 消息处理程序

BOOL CBinaryFileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBinaryFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBinaryFileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBinaryFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBinaryFileDlg::OnBnClickedSelectFile()
{
	// TODO: 在此添加控件通知处理程序代码

	BOOL isOpen = TRUE;     //是否打开(否则为保存)  
	CString defaultDir = _T("C:\\");   //默认打开的文件路径  
	CString fileName = L"";         //默认打开的文件名  
	CString filter = L"All Files|*.*||";   //文件过虑的类型  
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"E:\\FileTest\\test.doc";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath;

	if (result==IDOK) {
		filePath = openFileDlg.GetPathName();
		SetDlgItemText(IDC_PATH, filePath);
	}
}



void CBinaryFileDlg::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码

	BOOL isOpen = FALSE;     //是否打开(否则为保存)  
	CString defaultDir = _T("C:\\");   //默认打开的文件路径  
	CString fileName = L"";         //默认打开的文件名  
	CString filter = L"All Files|*.*||";   //文件过虑的类型  
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"E:\\FileTest\\test.doc";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath;

	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
		SetDlgItemText(IDC_SAVE_PATH, filePath);
	}
}


void CBinaryFileDlg::OnBnClickedRun()
{
	CString path;
	GetDlgItemText(IDC_PATH, path);
	std::ifstream fin(path, std::ios::binary);

	CString save;
	GetDlgItemText(IDC_SAVE_PATH, save);
	std::ofstream fout(save, std::ios::binary | std::ios::app);


	CFileStatus fileStatus;

	int size;
	if (CFile::GetStatus(path, fileStatus))
	{
		size = fileStatus.m_size;
	}
	my_process.SetRange32(0, size);

	int p = 0;

	while (!fin.eof())
	{
		char szBuf[1] = { 0 };
		fin.read(szBuf, sizeof(char) * 1);

		if (fout.bad())
		{
			MessageBox(L"Bad");
			break;
		}
		fout.write(szBuf, sizeof(char) * 1);

		my_process.SetPos(p++);
	}

	fin.close();
	fout.close();

	
}
