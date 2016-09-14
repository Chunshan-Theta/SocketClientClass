#ifndef SocketClient_H_INCLUDED
#define SocketClient_H_INCLUDED
#pragma once


#include <WINSOCK2.H>
#include <STDIO.H>
#include <string>
#include <iostream>
#pragma  comment(lib,"ws2_32.lib")
using namespace std;

class SocketClient
{
public:
	string ReceiveContent;
	SocketClient();
	~SocketClient();


	void SendData(string IP_addr, int Port, string content);
	
	
protected:

private:
	
	SOCKET sclient;
	sockaddr_in serAddr;
	void CreatConnect(string sendData);
	void CloseConnect();
	string GetReceive();

	void SetTargetServer(string IP_addr, int Port);
	void TCPClient_initialization();	
	void WinWSAdown();
	void WinWSAUp();
};



#endif //SocketClient_H_INCLUDED
