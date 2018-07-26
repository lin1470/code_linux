#include<WinSock2.h>
#include<iostream>
#include <afxres.h>

using namespace std;
#pragma comment(lib,"WS2_32")
class CInitSock
{
public:
    CInitSock(BYTE minorVer=2,BYTE majorVer=2)
    {
        WSADATA wsaData;
        WORD sockVersion=MAKEWORD(minorVer,majorVer);
        if(WSAStartup(sockVersion,&wsaData)!=0)
        {
            exit(0);
        }
    }
    ~CInitSock()
    {
        WSACleanup();
    }
};

CInitSock initSock;
void IP()
{
    int i;
    char szHost[256];
    gethostname(szHost,256);
    hostent *pHost=gethostbyname(szHost);
    hostent *pHost2 = gethostbyname("www.baidu.com");
    in_addr addr,baiduAddr;

    char *p=pHost->h_addr_list[0];
    char *p2 = pHost2->h_addr_list[0];
    memcpy(&baiduAddr.S_un.S_addr,p,pHost2->h_length);
    memcpy(&addr.S_un.S_addr,p,pHost->h_length);
    char *szIp=inet_ntoa(addr);
    cout<< "本机器的主机名："<< szHost << endl << "本机的ip地址:" << szIp << endl
        <<"学号:2015101017 姓名:李柱霖" << endl<< endl;

    char *baiduIp = inet_ntoa(baiduAddr);
    cout << "www.baidu.com 的IP地址:" << baiduIp << endl
         << "学号:2015101017 姓名:李柱霖"<< endl;
}

int main()
{
    IP();
    return 0;
}
