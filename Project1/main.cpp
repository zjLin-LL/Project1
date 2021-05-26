#include"ftpupload.h"

int main()
{
	ftpup ftp;
	ftp.connect("192.168.1.126","pi","raspberry");
	return 0;
}