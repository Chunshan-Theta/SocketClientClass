#include "SocketClient.h"
#include <string>



int main() {
	
	SocketClient a;
	
	
	for (int i = 0; i < 10; i++) {
		a.SendData("192.168.1.150", 27015, "hello!!! TCP Server"+to_string(i));		
		cout << a.ReceiveContent << endl;
		
		Sleep(2000);
	}
	cout << a.ReceiveContent << endl;
	system("Pause");

	return 0;
	
}


