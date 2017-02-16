#ifndef _PROXY_H_
#define _PROXY_H_

#include <WinSock2.h>  
#include <string>  
#include <vector>  
#pragma comment(lib, "ws2_32.lib")

using namespace std;  

enum PROXY_STATUS  
{  
	PROXY_STATUS_SUCCESS = 1,  
	PROXY_STATUS_CONNECT_PROXY_FAIL,  
	PROXY_STATUS_NOT_CONNECT_PROXY,  
	PROXY_STATUS_CONNECT_SERVER_FAIL,
};  

enum PROXY_TYPE
{
	PROXY_TYPE_HTTP = 1,
	PROXY_TYPE_SOCK4,
	PROXY_TYPE_SOCK5,
};

class CProxy  
{  
public:  
	CProxy(PROXY_TYPE type, string ip, u_short port, string username, string password)  
		:m_proxyType(type), m_proxyIp(ip), m_proxyPort(port), m_proxyUserName(username), m_proxyUserPwd(password)  
	{}  

	~CProxy(){};  

	PROXY_STATUS ConnectProxyServer(SOCKET socket);  
	PROXY_STATUS ConnectServer(SOCKET socket, string ip, int port);  

private:  
	PROXY_STATUS ConnectByHttp(SOCKET socket, string ip, int port);  
	PROXY_STATUS ConnectBySock4(SOCKET socket, string ip, int port);  
	PROXY_STATUS ConnectBySock5(SOCKET socket, string ip, int port);  

public:
	bool Send(SOCKET socket, const char* buf, int len);  
	int  Recv(SOCKET socket, char* buf, int bufLen);  

private:  
	PROXY_TYPE	m_proxyType;  
	string		m_proxyIp;  
	int			m_proxyPort;  
	string		m_proxyUserName;  
	string		m_proxyUserPwd;  
	bool		m_blnProxyServerOk;  
};  

struct TSock4req1   
{   
	char VN;   
	char CD;   
	unsigned short Port;   
	unsigned long IPAddr;   
	char other;   
};   

struct TSock4ans1   
{   
	char VN;   
	char CD;   
};  

struct TSock5req1   
{   
	char Ver;   
	char nMethods;   
	char Methods;   
};   

struct TSock5ans1   
{   
	char Ver;   
	char Method;   
};   

struct TSock5req2   
{   
	char Ver;   
	char Cmd;   
	char Rsv;   
	char Atyp;   
	char other;   
};   

struct TSock5ans2   
{   
	char Ver;   
	char Rep;   
	char Rsv;   
	char Atyp;   
	char other;   
};   

struct TAuthreq   
{   
	char Ver;   
	char Ulen;   
	char Name;   
	char PLen;   
	char Pass;   
};   

struct TAuthans   
{   
	char Ver;   
	char Status;   
};   

#endif
