#include "stdafx.h"
#include "Core.h"


Core::Core()
{
}


Core::~Core()
{
}

Core* Core::GetCoreInstance(CoreConfig config) {
	// ʵ�����ں�
	Core *instance = new Core();

	// ��ʼ��Socket
	instance->InitSocket(config.port);

	return instance;
}

void Core::Initiate() {
}


bool Core::InitSocket(UINT port) {

	Message msg;
	msg.type = _T("ϵͳ��Ϣ");
	msg.content = _T("��ʼ�� Socket");

	SendMessage(AfxGetMainWnd()->m_hWnd , UM_SHOWMESSAGE,NULL, (LPARAM)&msg);

	return 0;
}

DWORD Core::SocketListenThread(LPVOID p) {

	OutputDebugString(_T("thread start"));

	HWND *s = (HWND*)p;



	Message msg;
	msg.type = _T("ϵͳ��Ϣ");
	msg.content = _T("�����߳�����...");

	SendMessageW(
		*s,
		UM_SHOWMESSAGE,
		NULL, (LPARAM)&msg
	);
	while (1) {
	}


	return 0;
}

