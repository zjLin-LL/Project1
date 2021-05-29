#include"ftpupload.h"
#include "cvImage.h"
#include "MShot.h"

string IP = "192.168.1.126";
string USERNAME = "pi";
string PASSWORD = "raspberry";

string PATTERNNAME = "pattern.png";
string TARGETPATH = "/home/pi/pattern";

string SOURCEPATH = "C:/Users/LLL/Desktop/1.png";


int main()
{
	ftpup ftp;
	if (!(ftp.connect(IP, USERNAME, PASSWORD)))
	{
		cout << "Á¬½ÓÊ§°Ü" << endl;
		system("pause");
	}



	ftp.upload(SOURCEPATH,PATTERNNAME,TARGETPATH);



	ftp.disconnect();
	return 0;
}