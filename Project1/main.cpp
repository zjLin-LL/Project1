#include"ftpupload.h"
#include "cvImage.h"
#include "MShot.h"

string IP = "192.168.1.126";
string USERNAME = "pi";
string PASSWORD = "raspberry";

string PATTERNNAME = "pattern.png";
string TARGETPATH = "/home/pi/pattern";

string SOURCEPATH = "C:/Users/LLL/Desktop/1.png";

string datapath = "D:/data";


int main()
{
	MShot cam;
	ftpup ftp;
	if (!(ftp.connect(IP, USERNAME, PASSWORD)))
	{
		cout << "Á¬½ÓÊ§°Ü" << endl;
		system("pause");
		return 0;
	}

	ftp.upload(SOURCEPATH,PATTERNNAME,TARGETPATH);
	cam.GrabImage(1, datapath);


	ftp.disconnect();
	return 0;
}