#include "stdafx.h"
#include "Core.h"


Core::Core()
{
}


Core::~Core()
{
}

Core* Core::GetCoreInstance(CoreConfig config) {
	// 实例化内核
	Core *instance = new Core();

	// 初始化Socket
	instance->InitSocket(config.port);

	return instance;
}

void Core::Initiate() {
}


bool Core::InitSocket(UINT port) {

	Message msg;
	msg.type = _T("系统消息");
	msg.content = _T("初始化 Socket");

	SendMessage(AfxGetMainWnd()->m_hWnd , UM_SHOWMESSAGE,NULL, (LPARAM)&msg);

	return 0;
}

DWORD Core::SocketListenThread(LPVOID p) {

	OutputDebugString(_T("thread start"));

	HWND *s = (HWND*)p;



	Message msg;
	msg.type = _T("系统消息");
	msg.content = _T("监听线程启动...");

	SendMessageW(
		*s,
		UM_SHOWMESSAGE,
		NULL, (LPARAM)&msg
	);
	while (1) {
	}


	return 0;
}

