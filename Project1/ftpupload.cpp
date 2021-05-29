#include "ftpupload.h"

bool ftpup::connect(string IP, string uesrname, string key)
{
	

	hint = InternetOpen(0, INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);
	if (hint == NULL)
	{
		return false;
	}
	//创建ftp连接
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

bool ftpup::upload(string sourcepath, string patternname, string target)
{
	if (FtpSetCurrentDirectory(hftp, target.c_str()))
	{
		FtpPutFile(hftp, sourcepath.c_str(), patternname.c_str(), FTP_TRANSFER_TYPE_BINARY, 0);
		return true;
	}
	return false;
}