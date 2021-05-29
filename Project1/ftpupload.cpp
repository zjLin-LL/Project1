#include "ftpupload.h"

bool ftpup::connect(string IP, string uesrname, string key)
{
	hint = InternetOpen(0, INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);
	if (hint == NULL)
	{
		return false;
	}
	//����ftp����
	hftp = InternetConnect(hint, IP.c_str(), 21, uesrname.c_str(), key.c_str(), INTERNET_SERVICE_FTP, 0, 0);
	if (hftp == NULL)
	{
		return false;
	}
	
	return true;
}

void ftpup::disconnect()
{
	InternetCloseHandle(hftp);
	InternetCloseHandle(hint);
}