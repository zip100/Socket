// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Winsock2.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;

	int err;
	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return 0;
	}
	//�����ͻ���socket
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);

	//��������ַ
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(4000);
	//���ӷ�����

	//�ȴ����շ���������Ӧ
	char recvBuf[100];
	memset(recvBuf, 0, 100);
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	int r = 0;
	do//��������������ӣ�ֱ�����ر�
	{
		printf("receiving.....\n");
		r = recv(sockClient, recvBuf, 100, 0);
		printf("receive end.....\n");
		printf("data from server: %s\n", recvBuf);
		char sendBuf[100];
		printf("input the message to send[1-100]: ");
		//gets(sendBuf);
		printf("sending.....\n");
		r = send(sockClient, sendBuf, strlen(sendBuf) + 1, 0);
		printf("send ended. waiting for server\n");

	} while (r != SOCKET_ERROR);
	printf("server connect error! app will exit\n");
	system("PAUSE");
	closesocket(sockClient);
	WSACleanup();

    return 0;
}

