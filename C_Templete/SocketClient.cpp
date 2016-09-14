//Client

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "SocketClient.h"
#include <string>


using namespace std;



SOCKET sclient;
sockaddr_in serAddr;
string ReceiveContent = "None";
void SocketClient::WinWSAUp() {
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		system("Pause");
	}
	
}
void SocketClient::WinWSAdown() {
	WSACleanup();
}
void SocketClient::TCPClient_initialization() {
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{

		system("Pause");
	}
}
void SocketClient::SetTargetServer(string IP_addr, int Port) {
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(Port);
	serAddr.sin_addr.s_addr = inet_addr(IP_addr.c_str());
}
string SocketClient::GetReceive() {
	char recData[255];
	int ret = recv(sclient, recData, 255, 0);
	if (ret > 0)
	{
		recData[ret] = 0x00;
		return recData;

	}
}
void SocketClient::CloseConnect() {
	closesocket(sclient);
	//printf("zzZ....");
	//Sleep(SleepTime);
	//system("Pause");
	//printf("Next Step\n");
}
void SocketClient::CreatConnect(string sendData) {

	sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{
		printf("connect error !");
		closesocket(sclient);
		system("Pause");
		//return 1;
	}


	//string new_data = to_string(i)+"."+sendData +"\n";
	string new_data = "From C++ Client:" + sendData + "\n";
	send(sclient, new_data.c_str(), strlen(new_data.c_str()), 0);
}

void SocketClient::SendData(string IP_addr, int Port,string content)
{
#ifdef _WIN32
	WinWSAUp();
#endif

	TCPClient_initialization();

	SetTargetServer(IP_addr, Port);

	CreatConnect(content);					
	ReceiveContent = GetReceive();
		
		
	CloseConnect();

#ifdef _WIN32
	WinWSAdown();
#endif
	
	
}
SocketClient::SocketClient() {//create
	//cout <<"TCP Start!"<<endl;
}
SocketClient::~SocketClient() //destructor
{
	//cout <<"TCP Closed!"<<endl;
}