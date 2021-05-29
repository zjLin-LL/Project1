#include "MShot.h"


bool MShot::OpenCam()
{
	dvpRefresh(&count);
	for (dvpUint32 i = 0; i < count; i++)
	{
		status = dvpEnum(i, &info);
		if (status == DVP_STATUS_OK)
		{
			//打开相机
			status = dvpOpenByName(info.FriendlyName, OPEN_NORMAL, &pHandle);
			if (status == DVP_STATUS_OK)
			{
				status = dvpLoadDefault(pHandle);
				return true;
			}
		}
	}
	return false;
}

bool MShot::CloseCam()
{
	status = dvpClose(pHandle);
	if (status == DVP_STATUS_OK)
		return true;
	else
		return false;
}

bool MShot::SetExposure(double Etime)
{
	status = dvpSetExposure(pHandle, Etime);
	if (status == DVP_STATUS_OK)
		return true;
	else
		return false;
}

bool MShot::SetGain(float  Gain)
{
	status = dvpSetAnalogGain(pHandle, Gain);
	if (status == DVP_STATUS_OK)
		return true;
	else
		return false;
}

bool MShot::OpenStream()
{
	status = dvpStart(pHandle);//打开视频流
	if (status == DVP_STATUS_OK)
		return true;
	else
		return false;
}

bool MShot::CloseStream()
{
	status = dvpStop(pHandle);//关闭视频流
	if (status == DVP_STATUS_OK)
		return true;
	else
		return false;
}

bool MShot::GrabImage(int ImageIndex, string captureImageFolder)
{
	status = dvpGetFrame(pHandle, &frame, &buffer, 5000);
	if (1)
	{
		// 将图像保存为图片文件
		std::ostringstream buf;
		buf << "/Image_"<< ImageIndex <<".bmp" ;
		strImageInfo = buf.str();
		strImageInfo = captureImageFolder + strImageInfo;
		status = dvpSavePicture(&frame, buffer, strImageInfo.c_str(), 100);
		return true;
	}
	else
		return false;
}





