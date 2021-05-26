#include "ftpupload.h"

int ftpup::connect(string IP, string uesrname, string key)
{

	HINTERNET hint;
	HINTERNET hftp;
	hint = InternetOpen(0, INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);
	if (hint == NULL)
	{
		return -1;
	}
	//创建ftp连接
	hftp = InternetConnect(hint, IP.c_str(), 21, uesrname.c_str(), key.c_str(), INTERNET_SERVICE_FTP, 0, 0);
	if (hftp == NULL)
	{
		return -1;
	}
	
	return 0;
}