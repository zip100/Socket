
// SnowManDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SnowMan.h"
#include "SnowManDlg.h"
#include "afxdialogex.h"

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


// CSnowManDlg �Ի���



CSnowManDlg::CSnowManDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SNOWMAN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSnowManDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MESSAGE, message_list);
}

BEGIN_MESSAGE_MAP(CSnowManDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(UM_SHOWMESSAGE, CSnowManDlg::DisplayResult)
END_MESSAGE_MAP()




// CSnowManDlg ��Ϣ�������

LRESULT CSnowManDlg::DisplayResult(WPARAM wParam, LPARAM lParam) {
	Message* msg = (Message*)lParam;
	// InsertMessage(msg->type, msg->content);


	int count = message_list.GetItemCount();
	CString str;
	str.Format(_T("%d"), count);
	MessageBox(str);

	 InsertMessage(_T("sfsdfg"), _T("asdasd"));
	return 0;
}

BOOL CSnowManDlg::OnInitDialog()
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
	CoreConfig config;
	config.port = 988;
	m_Core = Core::GetCoreInstance(config);
	m_Core->Initiate();

	// ��ʼ����Ϣ�б�
	initMessageList();
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSnowManDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSnowManDlg::OnPaint()
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
HCURSOR CSnowManDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSnowManDlg::initMessageList() 
{
	HWND h = AfxGetMainWnd()->m_hWnd;

	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	message_list.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	message_list.SetExtendedStyle(message_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	// Ϊ�б���ͼ�ؼ��������   
	message_list.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width() / 5, 0);
	message_list.InsertColumn(1, _T("ʱ��"), LVCFMT_CENTER, rect.Width() / 5, 1);
	message_list.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width() / 5 * 3, 2);

	InsertMessage(_T("ϵͳ��Ϣ"), _T("��ʼ���ɹ�"));
}

void CSnowManDlg::InsertMessage(CString msgType, CString content) {

	CTime m_time;
	m_time = CTime::GetCurrentTime();
	int count = message_list.GetItemCount();
	int pos = count*3;

	message_list.InsertItem(count, msgType);
	message_list.SetItemText(count,1, m_time.Format(_T("%Y-%m-%d %H:%M:%S")));
	message_list.SetItemText(count, 2, content);
}