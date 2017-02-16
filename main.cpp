#include "proxy.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <WinSock2.h>  
#include <cstring>
#include <memory>

int main()
{
	long proxy_type = 2;	
	WORD sockVersion = MAKEWORD(2,2);
	WSADATA data;
	if(WSAStartup(sockVersion, &data) != 0)
		return 0;

	/* ���軯 SOCK5 IP��PORT */
	CProxy proxy(PROXY_TYPE_SOCK5, "127.0.0.1", 1080, "", "");
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	/* ����SOCK5 */
	proxy.ConnectProxyServer(s);
	/* ����Ŀ�� IP��PORT */
	proxy.ConnectServer(s, "116.116.117.225", 18080);

	char buf[] = "hello";
	/* ������Ϣ��Ŀ��(ͨ��SOCK5) */
	proxy.Send(s, buf, strlen(buf));
	/* ����Ŀ��ذ� */
	proxy.Recv(s, buf, strlen(buf));

	printf("@_@\n");
	_getch();
	return 0;
}