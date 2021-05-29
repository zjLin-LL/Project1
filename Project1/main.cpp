#include"ftpupload.h"

string IP = "192.168.1.126";

string USERNAME = "pi";

string PASSWORD = "raspberry";

int main()
{
	ftpup ftp;
	if (!(ftp.connect(IP, USERNAME, PASSWORD)))
	{
		cout << "Á¬½ÓÊ§°Ü" << endl;
		system("pause");
	}

	return 0;
}