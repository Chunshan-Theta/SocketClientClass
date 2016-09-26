#include "SocketClient.h"
#include <string>



int main() {
	
	SocketClient a;
	
	/*
	for (int i = 1; i > 0; i++) {
		a.SendData("192.168.1.150", 27015, "hello!!! TCP Server"+to_string(i));		
		cout << " Server : " << a.ReceiveContent << endl;
		
		Sleep(1000);
	}
	*/
	a.SendLoopData("192.168.1.150", 27015, "hello!!! TCP Server" );
	system("Pause");

	return 0;
	
}


