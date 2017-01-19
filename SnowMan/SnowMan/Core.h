#pragma once
#include "Resource.h"

class Core
{
public:
	static Core* m_pinstance;
	Core();
	~Core();
	static Core* GetCoreInstance(CoreConfig);
	void Initiate();
	bool InitSocket(UINT);
	static DWORD WINAPI SocketListenThread(LPVOID);
};

