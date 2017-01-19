
// BinaryFileDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BinaryFile.h"
#include "BinaryFileDlg.h"
#include "afxdialogex.h"
#include "fstream"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CBinaryFileDlg �Ի���



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


// CBinaryFileDlg ��Ϣ�������

BOOL CBinaryFileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBinaryFileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBinaryFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBinaryFileDlg::OnBnClickedSelectFile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	BOOL isOpen = TRUE;     //�Ƿ��(����Ϊ����)  
	CString defaultDir = _T("C:\\");   //Ĭ�ϴ򿪵��ļ�·��  
	CString fileName = L"";         //Ĭ�ϴ򿪵��ļ���  
	CString filter = L"All Files|*.*||";   //�ļ����ǵ�����  
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	BOOL isOpen = FALSE;     //�Ƿ��(����Ϊ����)  
	CString defaultDir = _T("C:\\");   //Ĭ�ϴ򿪵��ļ�·��  
	CString fileName = L"";         //Ĭ�ϴ򿪵��ļ���  
	CString filter = L"All Files|*.*||";   //�ļ����ǵ�����  
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
